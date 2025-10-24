#!/bin/bash

remote_user="simon"
local_dir="./misc/graph"
remote_dir="/home/simon/tree"

if [[ $USER =~ "focant" ]]; then
	remote_user="aurel"
	local_dir="./misc/graph"
	remote_dir="/home/aurel/tree"
fi


scp -P 4242 ${local_dir}/tree.dot ${remote_user}@born2beroot.duckdns.org:${remote_dir}/tree.dot

ssh -p 4242 ${remote_user}@born2beroot.duckdns.org "dot -Tpdf ${remote_dir}/tree.dot -o ${remote_dir}/tree.pdf"

scp -P 4242 ${remote_user}@born2beroot.duckdns.org:${remote_dir}/tree.pdf ${local_dir}/tree.pdf

open ${local_dir}/tree.pdf

