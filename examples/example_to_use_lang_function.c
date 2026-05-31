#include <stdio.h>
#include "system.h"

int main() {
  printf("Hi, user!\n");
  if (lang() == 0) {
    printf("You use language: C!\n");
  }
  else if (lang() == 1) {
    printf("You use language: C++!\n");
  }
  else if (lang() == 2) {
    printf("You use language: Obj C!\n");
  }
  else if (lang() == 3) {
    printf("You use language: Obj C++!\n");
  }
  else {
    printf("You use unknow processor!");
  }
}
