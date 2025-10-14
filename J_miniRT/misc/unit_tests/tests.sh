#!/bin/bash

pip -V | grep "\.venv" || source unit_tests/.venv/bin/activate

cd ./unit_tests && behave; cd ..
