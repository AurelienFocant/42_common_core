import pexpect
import sys

def test_shell(cmd, shell_path):
    child = pexpect.spawn(shell_path, ['-c', cmd], encoding='utf-8', timeout=5)
    child.expect(pexpect.EOF) 
    output = child.before.strip()
    exit_code = child.exitstatus if child.exitstatus is not None else 0
    return output, exit_code

def main():
    print(f"\n\n\n ###################################### \n\n\n")
    print(f"\tPICOSHELL TESTER")
    print(f"\n\n\n ###################################### \n\n\n")


    input_file = open('./unit_tests/shell_commands.txt', 'r')
    log_file = open('./unit_tests/test_results', 'w')
    cmd = input_file.readline()
    x = 0 
    while cmd:
     # print(f"\nTesting command: {cmd}\n")
      pico_output, pico_exit = test_shell(cmd, './picoshell')
      bash_output, bash_exit = test_shell(cmd, 'bash')

      passed = True
      x += 1
      if bash_output != pico_output:
         result = f"❌ Command {x}: FAILED - {cmd} - pico:{pico_output} \n- bash:{bash_output}"
         print(result)
         log_file.write(result + "\n")
         passed = False
      if bash_exit != pico_exit:
         result = f"❌ Exit Code {x}: FAILED - pico:{pico_exit} \n- bash:{bash_exit}"
         print(result)
         log_file.write(result + "\n")
         passed = False
      if passed:
         result = f"✅ Test {x}: PASSED - {cmd}"
         print(result)
         log_file.write(result + "\n")
      cmd = input_file.readline()

    input_file.close()


if __name__ == "__main__":
    main()


# if send commands from list
#      test_commands = [
#        '/usr/bin/echo HelloWorld',
#        '/bin/ls -lv',
#        '/usr/bin/cat Makefile | /usr/bin/wc -l',
#      ]
#      for cmd in test_commands:
#        print(f"\nTesting command: {cmd}\n")

# if run ./picoshell without -c
#   if shell_path == './picoshell':
#        child = pexpect.spawn(shell_path, encoding='utf-8', timeout=5, echo=False)
#        child.expect('pico >') 
#        child.sendline(cmd)
#        child.expect() ici il faudrait la liste des expected outputs selon bash
#        child.expect(['pico >', pexpect.EOF])
#        child.expect(pexpect.EOF) 
