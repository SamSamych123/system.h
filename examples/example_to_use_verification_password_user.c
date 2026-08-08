#include "../system.h"
#include <stdio.h>

int main() {
  char real_password_user[] = "Okak, okak-kak, and programming time in time table";

  printf("Hi!\n");
  if (verification_password_user(real_password_user, sizeof(real_password_user)) == 0) {
    printf("Succes!\n");
  }
  else {
    printf("No!\n");
  }
}
