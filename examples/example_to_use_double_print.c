#include "../system.h"
#include <stdio.h>

int main() {
  int c = double_print("Hello, wo", "rld!\n", stdout);
  if (c == 1) {
    printf("Error for varible!\n");
  }
  else if (c == 2) {
    printf("Error for input strings!\n");
  }
  return 0;
}
