#include <stdio.h>
#include "lib.c"

int main() {
  // puts("attempting printing fizzbuzz");
  // fizzbuzz_print(30);
  // puts("attempting buffer version of fizzbuzz");
  // char result[1000] = {0};
  // fizzbuzz_buffer(result, sizeof(result), 10);
  // printf("%s\n", result);
  // puts("attempting pointer version of fizzbuzz");
  // char *buffer = fizzbuzz_pointer(50);
  // printf("%s\n", buffer);
  // free(buffer);
  // int primesBelow = 20;
  // int ansBuf[primesBelow];
  // int primeCount = prime_sieve(ansBuf, primesBelow);
  // printf("number of primes below %d: \n%d\n",primesBelow, primeCount);
  // puts("final list of primes: ");
  // for (int i=0; i<primeCount-1; i++){
  //   printf("%d, ", ansBuf[i]);
    
  // }
  // printf("%d.\n", ansBuf[primeCount-1]);

  char buffer[100] = {0};
  wordify(buffer, 100,15);
  puts(buffer);

  return 0;
}
