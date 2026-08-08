#include <stdio.h>
#include "../system.h"

int main() {
  printf("First text...\n");
  printf("Please, waiting 3 seconds\n");
  delay(3);

  printf("Second text...\n");
  printf("Please, waiting 0.7 seconds\n");
  delay(0.7);

  printf("Thriple text...\n");
  printf("Please, waiting 1 / 1000000 seconds (1 microseconds)\n");
  delay(1 / 1000000);

  return 0;
}
