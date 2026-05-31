#include <stdio.h>
#include "system.h"

int main() {
  printf("Hi, user!\n");
  #if ARCH == 0
    printf("You use OS type Windows!\n");
  #elif ARCH == 1
    printf("You use OS type Linux, Unix, Apple and other type OS!\n");
  #elif ARCH == 2
    printf("You use OS type FreeBSD!\n");
  #elif ARCH == 3
    printf("You use OS type 'Toy OS'!\n");
  #else
    printf("You use unknow OS type!\n");
  #endif
}
