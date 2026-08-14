# System.h — automated library management system for system queries

**System.h** is a simple and uniform interface for creating architectures, operating system, computer, applications, tap reports, birthday party input/output, and steam, as well as executing commands. The library is written in C and is compatible with C++.

# System.h - is a cross-platform C library for system calls

**System.h** provides a simple and consistent interface for defining architecture, operating system, compiler, delays, screen cleaning, name and password entry/verification, and command execution. The library is written in pure C and is compatible with C++.

## License
LGPL v2.1. Details in the LICENSE file.

## Features
- Architecture definition (x86_64, i386, ARM, ARM64, RISC-V 32/64/128)
- OS type definition (Windows, Unix, FreeBSD, ToyOS)
- Definition of a specific OS (Windows, Linux, Apple, Android, UNIX, FreeBSD, ToyOS)
- Definition of the compiler (GCC, Clang, MSVC)
- Delay in seconds (Windows, Unix and fallback support)
- Character-by-character delayed printing
- Execution of system commands
- Universal logging with levels (errors, warnings, information, commands)
- Screen clearing (cls/clear/ANSI)
- Confirmation request with configurable default value (Y/n or y/N)
- Name input and verification (max. 30 characters)
- Password entry and verification (max. 100 characters)

## Installation and assembly
Copy the `system.c` and `system.h` to your project. Compile along with the main code:
```bash
gcc -c system.c -o system.o
gcc main.c system.o -o myapp
```

Or include 'system.c` directly in the build.

## Usage example

```
#include "system.h"
#include <stdio.h>

int main() {
printf("Architecture: %d\n", arch());
printf("OS type: %d\n", type_os());
printf("OS: %d\n", os());
printf("Compiler: %d\n", comp());

    if (conf_user("Continue?", 0)) {
        char name[31];
        name_user(name);
        printf("Hello, %s!\n", name);
    }

    clear_screen();
    print_with_delay("Hello, world!\n", 0.1);
    return 0;
}
```

## Porting

The library was tested on Linux (GCC, Clang) and should work on Windows (MinGW, MSVC), macOS, FreeBSD, Android. To add support for your OS, use macros at the beginning of `system.c` and `system.h`.

## Author

Sam Samych

## Thanks

Thanks to everyone who tested and helped with debugging!
