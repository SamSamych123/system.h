#include "system.h"
#include <stdio.h>

int main() {
  printf("=== System.h Demo ===\n");
  printf("Architecture: %d\n", arch());
  printf("OS type: %d\n", type_os());
  printf("OS: %d\n", os());
  printf("Compiler: %d\n", comp());
  printf("Lang: %d\n\n", lang());

  //triple_print("\033[31mHello", ", ", "World!\n\033[0m", stdout);
  //double_print("\033[32mHello", ", \033[0m\n", stdout);
  //print_in_color("Hello, user!\n", GREEN);

  if (conf_user("Continue with delayed printing?", 0)) {
    //clear_screen();
    print_with_delay("Hello from System.h!\n", 0.05);
    //print_in_color("Hello, user!\n", GREEN);
  } else {
    printf("Goodbye!\n");
  }

  char name[31];
  name_user(name, sizeof(name));
  printf("Nice to meet you, %s!\n", name);
  return 0;
}
