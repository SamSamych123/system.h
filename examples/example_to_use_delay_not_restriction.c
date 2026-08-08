#include <stdio.h>
#include "../system.h"

int main() {
  printf("First text...\n");
  printf("Please, waiting 3 seconds\n");
  delay_not_restrictions(3);

  printf("Second text...\n");
  printf("Please, waiting 0.7 seconds\n");
  delay_not_restrictions(0.7);

  printf("Thriple text...\n");
  printf("Please, waiting 1 / 1000000 seconds (1 microseconds)\n");
  delay_not_restrictions(1 / 1000000);

  printf("Tetris text...\n");
  printf("Please, waiting 1275483956478365 seconds\n");
  delay_not_restrictions(1275483956478365);

  return 0;
}
