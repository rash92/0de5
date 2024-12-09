#include <stdio.h>
#include "lib.c"

int main() {
  puts("attempting printing fizzbuzz");
  fizzbuzz_print(30);
  puts("attempting buffer version of fizzbuzz");
  char result[1000] = {0};
  fizzbuzz_buffer(result, sizeof(result), 50);
  printf("%s\n", result);
  puts("attempting pointer version of fizzbuzz");
  char *buffer = fizzbuzz_pointer(50);
  printf("%s\n", buffer);
  free(buffer);
  return 0;
}
