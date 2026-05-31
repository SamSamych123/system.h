#include <stdio.h>
#include "system.h"

int main() {
  printf("Hi, user!\n");
  #if OS == 0
    printf("You use OS 'Windows' (X32)!\n");
  #elif OS == 1
    printf("You use OS 'Windows' (X64)!\n");
  #elif OS == 2
    printf("You use OS 'Linux'!\n");
  #elif OS == 3
    printf("You use OS 'Mac OS'!\n");
  #elif OS == 4
    printf("You use OS from Apple, and not Mac OS!\n");
  #elif OS == 5
    printf("You use OS 'Unix' or Unix based!\n");
  #elif OS == 6
    printf("You use OS 'Android'!\n");
  #elif OS == 7
    printf("You use OS 'FreeBSD'!\n");
  #elif OS == 8
    printf("You use OS 'Toy OS'!\n");
  #else
    printf("You use unknow OS!\n");
  #endif
}
