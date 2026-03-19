#!/usr/bin/env python3

import subprocess

tests = [

    # ✅ VALID CASES
    ("3 4 +", "7"),
    ("9 3 -", "6"),
    ("5 6 *", "30"),
    ("8 2 /", "4"),
    ("7 7 * 7 -", "42"),
    ("5 1 2 + 4 * + 3 -", "14"),
    ("2 3 4 * +", "14"),
    ("9 5 2 + *", "63"),
    ("0 0 +", "0"),
    ("9 1 - 8 * 2 /", "32"),
    ("3     4      +", "7"),
    ("   3 4 +   ", "7"),

    # ❌ INVALID CASES
    ("", "Error"),
    ("   ", "Error"),
    ("+", "Error"),
    ("3 +", "Error"),
    ("3 4", "Error"),
    ("4 5 + -", "Error"),
    ("3 4 &", "Error"),
    ("5 0 /", "Error"),
    ("9 2 2 - /", "Error"),
]


def run_test(expression):
    try:
        result = subprocess.run(
            ["./RPN", expression],
            capture_output=True,
            text=True
        )
        output = result.stdout.strip()
        if not output:
            output = result.stderr.strip()
        return output
    except Exception:
        return "CRASH"


def main():
    passed = 0

    for expr, expected in tests:
        output = run_test(expr)

        if output == expected:
            print(f"[PASS] \"{expr}\" → {output}")
            passed += 1
        else:
            print(f"[FAIL] \"{expr}\"")
            print(f"  Expected: {expected}")
            print(f"  Got:      {output}")
            print()

    print("=" * 30)
    print(f"Passed {passed} / {len(tests)} tests")


if __name__ == "__main__":
    main()
