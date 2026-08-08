#include "../system.h"
#include <stdio.h>

int main() {
  if (conf_user("Created Linux kernel?", 0) == 1) {
    printf("Error: not found directiry \"kernel\"!\n");
  }
  else {
    printf("Okay...\n");
  }

  return 0;
}
