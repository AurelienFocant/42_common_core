import pexpect
import sys
import os
import shutil
import re
import argparse

def setup_parser():
    parser = argparse.ArgumentParser(
        description="tinyshell VS bash",
        formatter_class=argparse.ArgumentDefaultsHelpFormatter
    )

    parser.add_argument(
        "file_number",
        nargs="?",
        type=int,
        help="Number (1-9) of the test file to run. If omitted, all tests will run."
    )

    parser.add_argument(
        "-l", "--list",
        action="store_true",
        help="List all available test files and exit"
    )

    parser.add_argument(
        "-v", "--verbose",
        action="store_true",
        help="Show more detailed output for each test"
    )

    parser.add_argument(
        "--no-cleanup",
        action="store_true",
        help="Don't clean up test files after running"
    )

    return parser

def print_available_tests(files):
    print("\nAvailable test files:")
    for i, file_path in enumerate(files, 1):
        file_name = os.path.basename(file_path)
        category = file_name.split('_', 1)[1].rsplit('.', 1)[0].replace('_', ' ')
        print(f" {i}: {category}")

def normalize_output(output):
    output = re.sub(r'(tiny|/usr/bin/bash):', '', output)
    output = re.sub(r'-c: line\d+:', '', output)

    return output.strip()

def create_test_directory():
    test_dir = "./test_tmp"
    if not os.path.exists(test_dir):
        os.makedirs(test_dir)
    return test_dir

def test_shell(cmd, shell_path):
    try:
      child = pexpect.spawn(shell_path, ['-c', cmd], encoding='utf-8', timeout=1)
      child.expect(pexpect.EOF) 
      output = child.before.strip()
      child.close()
      exit_code = child.exitstatus if child.exitstatus is not None else 0
      return output, exit_code

    except pexpect.TIMEOUT:
      try:
        child.kill(0)
      except:
        pass
      return "TIMEOUT", 124

def run_tests(throughput_file, verbose=False):
    total = 0
    passed = 0

    input_file = open(throughput_file, 'r')
    log_file = open('./unit_tester/test_results', 'a')

    file_header = f"\n\n--- Testing {os.path.basename(throughput_file)} ---\n"
    print(file_header)
    log_file.write(file_header + "\n")

    cmd = input_file.readline().strip()
    line_num = 0

    while cmd:
        if not cmd or cmd.startswith('#'):
            cmd = input_file.readline().strip()
            continue

        line_num += 1
        total += 1

        pico_output, pico_exit = test_shell(cmd, './tinyshell')
        bash_output, bash_exit = test_shell(cmd, 'bash')

        normalized_pico = normalize_output(pico_output)
        normalized_bash = normalize_output(bash_output)

        test_passed = True

        if normalized_bash != normalized_pico:
             result = f"❌ Command {line_num}: FAILED - {cmd}"
             if verbose:
                 result += f"\n  tiny: {normalized_pico}\n  bash: {normalized_bash}"
             print(result)
             log_file.write(result + "\n")
             test_passed = False
        elif bash_exit != pico_exit:
             result = f"❌ Exit Code {line_num}: FAILED - {cmd}"
             if verbose:
                 result += f"\n  tiny: {pico_exit}, bash exit: {bash_exit}"
             print(result)
             log_file.write(result + "\n")
             test_passed = False
        
        if test_passed:
             result = f"✅ Test {line_num}: PASSED - {cmd}"
             print(result)
             log_file.write(result + "\n")
             passed += 1
             
        cmd = input_file.readline().strip()

    input_file.close()
    log_file.close()

    return {
        "total": total,
        "passed": passed,
        "failed": total - passed,
    }
"""
def cleanup_test_files():
    try:
        if os.path.exists(test_dir):
           shutil.rmtree(test_dir)
    except Exception as e:
        print(f"Cleanup error: {e}")
"""
def main():
    all_files = [
        './unit_tester/1_basic_commands.txt',
        './unit_tester/2_pipes_subshells.txt',
        './unit_tester/3_redirections.txt',
        './unit_tester/4_logical_operators.txt',
        './unit_tester/5_quotes.txt',
        './unit_tester/6_env.txt',
        './unit_tester/7_builtins.txt',
        './unit_tester/8_wildcard.txt',
        './unit_tester/9_error_and_go_crazy.txt',
        './unit_tester/10_githubtester.txt',
        './unit_tester/11_expand.txt'
    ]
    parser = setup_parser()
    args = parser.parse_args()

    print(f"\n\n\n ###################################### \n\n\n")
    print(f"\tPICOSHELL TESTER")
    print(f"\n\n\n ###################################### \n\n\n")

    if args.list:
        print_available_tests(all_files)
        return

    open('./unit_tester/test_results', 'w').close()
    
    if args.file_number is not None:
        if 1 <= args.file_number <= len(all_files):
            throughput_files = [all_files[args.file_number -1]]
            print(f"Running tests for file {args.file_number}: {os.path.basename(throughput_files[0])}")
        else:
            print(f"Error: Please provide a number between 1 and {len(all_files)}.")
            print_available_tests(all_files)
            return
    else:
        throughput_files = all_files
        print("Running tests for all files.")
    
    total_stats = {"total" : 0, "passed": 0, "failed": 0}

    for throughput_file in throughput_files:
        stats = run_tests(throughput_file, args.verbose)

        for key in total_stats:
            total_stats[key] += stats[key]

    print(f"\n\n--- TEST SUMMARY ---")
    print(f"Total tests run: {total_stats['total']}")
    print(f"Tests passed:    {total_stats['passed']} ({total_stats['passed']/total_stats['total']*100:.1f}%)")
    print(f"Tests failed:    {total_stats['failed']}")
"""
    if not args.no_cleanup:
        cleanup_test_files()
    else:
        print("\nSkipping cleanup as requested.")
"""
if __name__ == "__main__":
    main()
