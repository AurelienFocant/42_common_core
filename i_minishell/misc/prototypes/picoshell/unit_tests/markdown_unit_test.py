import pexpect
import sys

def sanitize_output(output):
    """
    Sanitize the output for Markdown table compatibility:
    - Replace newlines with spaces.
    - Escape pipes (`|`) to prevent breaking the table.
    - Truncate long outputs to a reasonable length.
    """
    # Replace newlines with spaces
    output = output.replace('\n', ' ')
    # Escape pipes to prevent breaking the table
    output = output.replace('|', '\\|')
    # Truncate long outputs (e.g., limit to 100 characters)
    if len(output) > 100:
        output = output[:100] + "..."
    return output

def test_shell(cmd, shell_path):
    child = pexpect.spawn(shell_path, ['-c', cmd], encoding='utf-8', timeout=5)
    child.expect(pexpect.EOF) 
    output = child.before.strip()
    exit_code = child.exitstatus if child.exitstatus is not None else 0
    return output, exit_code

def main():
    # Open a file to store the test results in Markdown format
    with open('./unit_tests/test_results.md', 'w') as log_file:
        # Write a Markdown header
        log_file.write("# Picoshell Test Results\n\n")
        log_file.write("## Test Summary\n\n")
        log_file.write("| Test # | Command | Status | Picoshell Output | Bash Output | Exit Code Match |\n")
        log_file.write("|--------|---------|--------|------------------|-------------|------------------|\n")

        file = open('./unit_tests/proto_shell_commands.txt', 'r')
        cmd = file.readline()
        x = 0 
        while cmd:
            pico_output, pico_exit = test_shell(cmd, './picoshell')
            bash_output, bash_exit = test_shell(cmd, 'bash')

            passed = True
            x += 1
            status = "✅ PASSED" if (bash_output == pico_output and bash_exit == pico_exit) else "❌ FAILED"
            exit_code_match = "✅" if bash_exit == pico_exit else "❌"

            # Sanitize outputs for Markdown compatibility
            pico_output_sanitized = sanitize_output(pico_output)
            bash_output_sanitized = sanitize_output(bash_output)

            # Write the result in Markdown table format
            log_file.write(f"| {x} | `{cmd.strip()}` | {status} | `{pico_output_sanitized}` | `{bash_output_sanitized}` | {exit_code_match} |\n")

            cmd = file.readline()

        file.close()

if __name__ == "__main__":
    main()
