#include <stdio.h>
#include "system.h"

int main() {
  printf("Hi, user!\n");
  if (os() == 0) {
    printf("You use OS 'Windows' (X32)!\n");
  }
  else if (os() == 1) {
    printf("You use OS 'Windows' (X64)!\n");
  }
  else if (os() == 2) {
    printf("You use OS 'Linux'!\n");
  }
  else if (os() == 3) {
    printf("You use OS 'Mac OS'!\n");
  }
  else if (os() == 4) {
    printf("You use OS from Apple, and not Mac OS!\n");
  }
  else if (os() == 5) {
    printf("You use OS 'Unix' or Unix base!\n");
  }
  else if (os() == 6) {
    printf("You use OS 'Android'!\n");
  }
  else if (os() == 7) {
    printf("You use OS 'FreeBSD'!\n");
  }
  else if (os() == 8) {
    printf("You use OS 'Toy OS'!\n");
  }
  else {
    printf("You use unknow OS!");
  }
}
