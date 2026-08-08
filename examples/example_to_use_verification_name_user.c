#include "../system.h"
#include <stdio.h>

int main() {
  char real_name_user[] = "APAGS";

  printf("Hi!\n");
  if (verification_name_user(real_name_user, sizeof(real_name_user)) == 0) {
    printf("Succes!\n");
  }
  else {
    printf("No!\n");
  }
}
