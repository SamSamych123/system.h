#include <stdio.h>
#include "system.h"

int main() {
  printf("Hi, user!\n");
  #if ARCH == 0
    printf("You use processor on X86 (I386)!\n");
  #elif ARCH == 1
    printf("You use processor on X86-64 (AMD64)!\n");
  #elif ARCH == 2
    printf("You use processor on ARM (32 bits or 64 bits)!\n");
  #elif ARCH == 3
    printf("You use processor on ARM64 (64 bits)!\n");
  #elif ARCH == 4
    printf("You use processor on RISC V (32 bits)!\n");
  #elif ARCH == 5
    printf("You use processor on RISC V (64 bits)!\n");
  #elif ARCH == 6
    printf("You use processor on RISC V (128 bits)!\n");
  #elif ARCH == 7
    printf("You use processor on PowerPC!\n");
  #elif ARCH == 8
    printf("You use processor on MIPS!\n");
  #elif ARCH == 9
    printf("You use processor on S390X!\n");
  #else
    printf("You use unknow processor!\n");
  #endif
}
