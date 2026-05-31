#include <stdio.h>
#include "system.h"

int main() {
  printf("Hi, user!\n");
  if (comp() == 0) {
    printf("You use compiler 'GCC' or GCC base!\n");
  }
  else if (comp() == 1) {
    printf("You use compiler 'Clang'!\n");
  }
  else if (comp() == 2) {
    printf("You use compiler from Vusial Studio!\n");
  }
  else if (comp() == 3) {
    printf("You use compiler 'MinGW' (32 bits)!\n");
  }
  else if (comp() == 4) {
    printf("You use compiler 'MinGW' (64 bits)!\n");
  }
  else if (comp() == 5) {
    printf("You use compiler 'Tiny C'!\n");
  }
  else if (comp() == 6) {
    printf("You use compiler 'ICC' (Intel C Compiler)!\n");
  }
  else if (arch() == 7) {
    printf("You use compiler 'POCC' (Pelles C)\n");
  }
  else {
    printf("You use unknow compiler!");
  }
}
