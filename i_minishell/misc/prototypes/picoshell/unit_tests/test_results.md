# Picoshell Test Results

## Test Summary

| Test # | Command | Status | Picoshell Output | Bash Output | Exit Code Match |
|--------|---------|--------|------------------|-------------|------------------|
| 1 | `usr/bin/echo Hello! This is Simon` | ❌ FAILED | `exec failed` | `/usr/bin/bash: line 1: usr/bin/echo: No such file or directory` | ✅ |
| 2 | `/usr/bin/echo HelloWorld` | ✅ PASSED | `HelloWorld` | `HelloWorld` | ✅ |
| 3 | `/bin/ls -lv` | ✅ PASSED | `total 220 -rw-r--r-- 1 slangero 2024_s19   2585 Jan 25 13:23 Makefile -rw-r--r-- 1 slangero 2024_s...` | `total 220 -rw-r--r-- 1 slangero 2024_s19   2585 Jan 25 13:23 Makefile -rw-r--r-- 1 slangero 2024_s...` | ✅ |
| 4 | `/usr/bin/cat Makefile | /usr/bin/wc -l` | ✅ PASSED | `92` | `92` | ✅ |
| 5 | `cat <<eof  | cat -e` | ❌ FAILED | `exec failed exec failed` | `/usr/bin/bash: line 1: warning: here-document at line 1 delimited by end-of-file (wanted `eof')` | ✅ |
| 6 | `cat <<eof >file1 | cat -e` | ❌ FAILED | `exec failed exec failed` | `/usr/bin/bash: line 1: warning: here-document at line 1 delimited by end-of-file (wanted `eof')` | ✅ |
| 7 | `cat <<eof | cat` | ❌ FAILED | `exec failed exec failed` | `/usr/bin/bash: line 1: warning: here-document at line 1 delimited by end-of-file (wanted `eof')` | ✅ |
| 8 | `cat <<eof | cat <<EOF` | ❌ FAILED | `exec failed exec failed` | `/usr/bin/bash: line 1: warning: here-document at line 1 delimited by end-of-file (wanted `eof') /us...` | ✅ |
| 9 | `echo hello >/dev/stdout | cat` | ❌ FAILED | `exec failed exec failed` | `hello` | ❌ |
| 10 | `echo hello >/dev/stdout | cat <<eof <<EOF` | ❌ FAILED | `exec failed exec failed` | `/usr/bin/bash: line 1: warning: here-document at line 1 delimited by end-of-file (wanted `eof') /us...` | ✅ |
| 11 | `/usr/bin/ls` | ❌ FAILED | `Makefile  file1  include  libft  misc  picoshell  src  tags  unit_tests` | `file1  include	libft  Makefile  misc  picoshell  src  tags  unit_tests` | ✅ |
