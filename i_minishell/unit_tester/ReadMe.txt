steps to setup same environment on other computer

1
cd ./0_minishell/unit_tester/

2 install virtualenv
pip3 install --user virtualenv

3 create new virtual env
virtualenv ftenv

4 activate
source ftenv/bin/activate

5 install dependencies
pip install -r ftenv/requirements.txt

6 run the tests
python3 pexpect_unit_test.py

7 deactivate
deactivate



