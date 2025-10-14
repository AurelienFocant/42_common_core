import subprocess

def test_shell(cmd, shell):
    proc = subprocess.Popen(
        [shell, '-c', cmd],
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        universal_newlines=True
    )
    stdout, stederr = proc.communicate()
    exit_code = proc.returncode
    return stdout, stderr, exit_code


def main():
      print(f"\n\n\n###################################### \n\n\n")
      print(f"\tPICOSHELL TESTER")
      print(f"\n\n\n ###################################### \n\n\n")

      test_commands = [
        '/usr/bin/echo "Hello World"',
        '/bin/ls -l',
        '/usr/bin/cat Makefile | wc -l',
      ]

      for cmd in test_commands:
        print(f"\nTesting command: {cmd}\n")

        pico_output, pico_error, pico_exit = test_shell(cmd, './picoshell')
        bash_output, bash_error, bash_exit = test_shell(cmd, 'bash')
        
        passed = True
        if bash_output != pico_output:
           print(f"pico: {pico_output}")
           print(f"bash: {bash_output}")
           print("output is different\n")
           passed = False
        if bash_exit != pico_exit:
           print(f"pico: {pico_exit}")
           print(f"bash: {bash_exit}")
           print("exit code is different\n")
           passed = False
        if passed:
           print("SAME SAME")
        else:
           print("BUT DIFFERENT\n\n\n")
        print("=====================================")
        print("")

if __name__ == "__main__":
        main()
