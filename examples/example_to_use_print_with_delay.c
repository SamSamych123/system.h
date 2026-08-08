#include "../system.h"

int main() {
  print_with_delay("Hi! This text with delay 0.3 seconds!\n", 0.3);
  print_with_delay("Hi! This text with delay 0.01 seconds!\n", 0.01);
  print_with_delay("Hi! This text with delay 1 seconds!\n", 1);
  print_with_delay("Hi! This text with delay 0.0000001 seconds!\n", 0.0000001);
  return 0;
}
