#!/bin/bash

tree_dir="/home/slangero/0minishell/misc/prototypes/picoshell/misc/tree"
user=simon

[[ $USER =~ focant ]] && user=aurel && tree_dir="/home/afocant/cursus_19/9_minishell/misc/prototypes/picoshell/misc/tree"

scp -P 4242 ${tree_dir}/tree.dot ${user}@born2beroot.duckdns.org:~/tree
ssh -p 4242 ${user}@born2beroot.duckdns.org "dot -Tpdf ~/tree/tree.dot -o ~/tree/tree.pdf"
scp -P 4242 ${user}@born2beroot.duckdns.org:~/tree/tree.pdf $tree_dir
open ${tree_dir}/tree.pdf
