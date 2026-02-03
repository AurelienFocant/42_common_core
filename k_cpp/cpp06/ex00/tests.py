import subprocess

def test_scalar_converter():
    test_values = ['a', '42', '65.7', '3.14f', '-3.14', 'nan', 'inf', '+inff', '-inf', '2147483648']

    for value in test_values:
        print(f"Testing value: {value}")
        result = subprocess.run(['./conversion', value], capture_output=True, text=True)
        print(result.stdout)
        if result.stderr:
            print("STDERR:", result.stderr)
        print("-" * 30)

if __name__ == "__main__":
    test_scalar_converter()