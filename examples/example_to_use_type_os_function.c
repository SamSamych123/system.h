#include <stdio.h>
#include "system.h"

int main() {
  printf("Hi, user!\n");
  if (type_os() == 0) {
    printf("You use OS type Windows!\n");
  }
  else if (type_os() == 1) {
    printf("You use OS type Linux, Unex base, Apple and other type OS!\n");
  }
  else if (type_os() == 2) {
    printf("You use OS type FreeBSD!\n");
  }
  else if (type_os() == 3) {
    printf("You use OS type 'Toy OS'!\n");
  }
  else {
    printf("You use unknow OS type!");
  }
}
