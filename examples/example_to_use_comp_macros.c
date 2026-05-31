#include <stdio.h>
#include "system.h"

int main() {
  printf("Hi, user!\n");
  #if COMP == 0
    printf("You use compiler 'GCC' or GCC base!\n");
  #elif COMP == 1
    printf("You use compiler 'Clang'!\n");
  #elif COMP == 2
    printf("You use compiler from Vusial Studio!\n");
  #elif COMP == 3
    printf("You use compiler 'MinGW' (32 bits)!\n");
  #elif COMP == 4
    printf("You use compiler 'MinGW' (64 bits)!\n");
  #elif COMP == 5
    printf("You use compiler 'Tiny C'!\n");
  #elif COMP == 6
    printf("You use compiler 'ICC' (Intel C Compiler)!\n");
  #elif COMP == 7
    printf("You use compiler 'POCC' (Pelles C)\n");
  #else
    printf("You use unknow processor!\n");
  #endif
}
