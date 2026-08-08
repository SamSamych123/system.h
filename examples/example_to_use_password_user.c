#include "../system.h"
#include <stdio.h>

int main() {
  printf("Hi!\n");

  char input_password_user[1023];
  password_user(input_password_user, sizeof(input_password_user));

  printf("New password (DO NOT SAVED!!!!): %s!\n", input_password_user);
  return 0;
}
