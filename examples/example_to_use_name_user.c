#include "../system.h"
#include <stdio.h>

int main() {
  printf("Hi!\n");

  char input_name_user[1023];
  name_user(input_name_user, sizeof(input_name_user));

  printf("Nice to meet you, %s!\n", input_name_user);
  return 0;
}
