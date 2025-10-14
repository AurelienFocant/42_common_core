#!/bin/bash

set -e

if [ ! -d "unit_tester/ftenv" ]; then
    echo "Setting up ftenv..."
    # pip3 install --user virtualenv
	cd unit_tester
    python3 -m virtualenv ftenv

	source ftenv/bin/activate
	pip install -r requirements.txt
	deactivate
	cd ..
fi

if [ -d "test_tmp" ]; then
    echo "Cleaning up previous test_tmp directory..."
    rm -rf test_tmp
fi

echo "Activating ftenv and running unit test..."
source unit_tester/ftenv/bin/activate
#pip3 list | grep pexpect
pip3 install pexpect
python3 unit_tester/pexpect_unit_test.py
deactivate

if [ -d "test_tmp" ]; then
    echo "Cleaning up test_tmp directory..."
    rm -rf test_tmp
fi

echo "Unit test completed."
