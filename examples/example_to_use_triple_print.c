#include "../system.h"
#include <stdio.h>

int main() {
  int c = triple_print("Hello, ", "world", "!\n", stdout);
  if (c == 1) {
    printf("Error for varible!\n");
  }
  else if (c == 2) {
    printf("Error for input strings!\n");
  }
  return 0;
}
