#include <stdio.h>
#include "system.h"

int main() {
  printf("Hi, user!\n");
  #if LANG == 0
    printf("You use language: C!\n");
  #elif LANG == 1
    printf("You use language: C++!\n");
  #elif LANG == 2
    printf("You use language: Obj C!\n");
  #elif LANG == 3
    printf("You use language: Obj C++!\n");
  #else
    printf("You use unknow processor!\n");
  #endif
}
