#include "../system.h"
#include <stdio.h>

int main() {
  char buffer[BUF_SIZE];

  printf("Enter string: ");
  input(buffer, BUF_SIZE);

  triple_print("You entered this string:\n```", buffer, "```\n", stdout);
  return 0;
}
