#include "system.h"
#include <stdio.h>

int main() {
    printf("=== SystemLib Demo ===\n");
    printf("Architecture: %d\n", arch());
    printf("OS type: %d\n", type_os());
    printf("OS: %d\n", os());
    printf("Compiler: %d\n", comp());

    if (conf_user("Continue with delayed printing?", 0)) {
        clear_screen();
        print_with_delay("Hello from SystemLib!\n", 0.1);
    } else {
        printf("Goodbye!\n");
    }

    char name[31];
    name_user(name);
    printf("Nice to meet you, %s!\n", name);
    return 0;
}