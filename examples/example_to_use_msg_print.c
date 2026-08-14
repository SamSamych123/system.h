#include "../system.h"
#include <stdio.h>

int main() {
  signed char level_program;
  unsigned char action_program;
  char* msg_program = "Test version";

  printf("Enter level [in number \"-2 ... 2\"]: ");
  scanf(" %hhd", &level_program);

  if (level_program == -1) {
    printf("Enter action [1 = exit, 0 = not exit]: ");
    scanf(" %hhd", &action_program);
  }
  else {
    action_program = 0;
  }

  //printf("Enter messeg: ");
  //fgets(msg_program, BUF_SIZE, stdin);

  msg_print(level_program, msg_program, action_program);
  return 0;
}
