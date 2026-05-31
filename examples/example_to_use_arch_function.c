#include <stdio.h>
#include "system.h"

int main() {
  printf("Hi, user!\n");
  if (arch() == 0) {
    printf("You use processor on X86 (I386)!\n");
  }
  else if (arch() == 1) {
    printf("You use processor on X86-64 (AMD64)!\n");
  }
  else if (arch() == 2) {
    printf("You use processor on ARM (32 bits or 64 bits)!\n");
  }
  else if (arch() == 3) {
    printf("You use processor on ARM64 (64 bits)!\n");
  }
  else if (arch() == 4) {
    printf("You use processor on RISC V (32 bits)!\n");
  }
  else if (arch() == 5) {
    printf("You use processor on RISC V (64 bits)!\n");
  }
  else if (arch() == 6) {
    printf("You use processor on RISC V (128 bits)!\n");
  }
  else if (arch() == 7) {
    printf("You use processor on PowerPC!\n");
  }
  else if (arch() == 8) {
    printf("You use processor on MIPS!\n");
  }
  else if (arch() == 9) {
    printf("You use processor on S390X!\n");
  }
  else {
    printf("You use unknow processor!");
  }
}
