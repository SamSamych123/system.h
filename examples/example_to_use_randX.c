#include "../system.h"
#include <stdio.h>

int main() {
  printf("Unsigned int 64 bit: %llu\n", urand64());
  printf("Unsigned int 32 bit: %u\n", urand32());
  printf("Unsigned int 16 bit: %hu\n", urand16());
  printf("Unsigned int 8 bit: %hhu\n", urand8());
  printf("Unsigned int range \"0 ... 10\": %llu\n\n", urand_in_range(0, 10));

  printf("Signed int 64 bit: %lld\n", rand64());
  printf("Signed int 32 bit: %d\n", rand32());
  printf("Signed int 16 bit: %hd\n", rand16());
  printf("Signed int 8 bit: %hhd\n", rand8());
  printf("Signed int range \"5 ... -5\": %lld\n", rand_in_range(5, -5));

  return 0;
}
