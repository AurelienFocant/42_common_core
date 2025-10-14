import pexpect
import sys

def test_shell(cmd, shell_path):
    child = pexpect.spawn(shell_path, ['-c', cmd], encoding='utf-8', timeout=5)
    child.expect(pexpect.EOF) 
    output = child.before.strip()
    exit_code = child.exitstatus if child.exitstatus is not None else 0
    return output, exit_code

def main():
    # Open a file to store the test results in CSV format
    with open('./unit_tests/test_results.csv', 'w') as log_file:
        # Write the CSV header
        log_file.write("Test #,Command,Status,Picoshell Output,Bash Output,Exit Code Match\n")

        file = open('./unit_tests/proto_shell_commands.txt', 'r')
        cmd = file.readline()
        x = 0 
        while cmd:
            pico_output, pico_exit = test_shell(cmd, './picoshell')
            bash_output, bash_exit = test_shell(cmd, 'bash')

            passed = True
            x += 1
            status = "PASSED" if (bash_output == pico_output and bash_exit == pico_exit) else "FAILED"
            exit_code_match = "YES" if bash_exit == pico_exit else "NO"

            # Write the result in CSV format
            log_file.write(f"{x},{cmd.strip()},{status},{pico_output},{bash_output},{exit_code_match}\n")

            cmd = file.readline()

        file.close()

if __name__ == "__main__":
    main()
