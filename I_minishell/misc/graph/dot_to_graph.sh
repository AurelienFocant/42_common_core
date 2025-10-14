#!/bin/bash

local_dir="./misc/graph"

if [[ $USER =~ "focant" ]]; then
	remote_user="aurel"
	remote_dir="/home/aurel/tree"
else
	remote_dir="/home/simon/tree"
	remote_user="simon"
fi

if dot -V 2>/dev/null; then
	dot -Tpdf ${local_dir}/tree.dot -o ${local_dir}/tree.pdf
else
	scp -P 4242 ${local_dir}/tree.dot ${remote_user}@born2beroot.duckdns.org:${remote_dir}/tree.dot
	ssh -p 4242 ${remote_user}@born2beroot.duckdns.org "PATH=/home/linuxbrew/.linuxbrew/bin/:/usr/bin; dot -Tpdf ${remote_dir}/tree.dot -o ${remote_dir}/tree.pdf"
	scp -P 4242 ${remote_user}@born2beroot.duckdns.org:${remote_dir}/tree.pdf ${local_dir}/tree.pdf
fi

open ${local_dir}/tree.pdf 2>/dev/null || evince ${local_dir}/tree.pdf 2>/dev/null || printf "can't open pdf file\n"
