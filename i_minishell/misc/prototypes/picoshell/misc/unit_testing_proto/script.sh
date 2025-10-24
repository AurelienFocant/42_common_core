#!/bin/zsh

s1=$(bash -c "echo hello")
s2="hello"

if [[ $s1 == $s2 ]]; then
        echo SUCCESS
else
        echo FAILURE
fi
