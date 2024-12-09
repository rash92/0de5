#include <stdlib.h>
#include <string.h>
#include <math.h>

int add(int a, int b) {
  return a + b;
}

char *fizzbuzz_pointer(int maxNum){
  int maxCharStringLen;
  int bufLen = 1000;
  // int bufLen = ((1 + maxNum / 15)*strlen("fizzbuzz, ") + (1 + maxNum / 3)*strlen("fizz, ") + (1 + maxNum / 5)* strlen("buzz, ") + maxNum*10)*sizeof(char);
  char *buffer = malloc(bufLen);

  for (int i=1; i<=maxNum; i++){
    if (i % 15 == 0){
      strncat(buffer, "fizzbuzz", bufLen);
    }else if (i % 3 == 0){
      strncat(buffer, "fizz", bufLen);
    } else if (i % 5 == 0){
      strncat(buffer, "buzz", bufLen);
    } else {
      //can only do numbers upto 10^9
      char str[10];
      snprintf(str, sizeof(str), "%d", i);
      strncat(buffer, str, bufLen);
    }
    if (i < maxNum){
      strncat(buffer, ", ", bufLen);
    }
  }
  strncat(buffer, ".", bufLen);
  return buffer;
}

void fizzbuzz_buffer(char *buffer, size_t bufLen, int maxNum){
  
  for (int i=1; i<=maxNum; i++){
    if (i % 15 == 0){
      strncat(buffer, "fizzbuzz", bufLen);
    }else if (i % 3 == 0){
      strncat(buffer, "fizz", bufLen);
    } else if (i % 5 == 0){
      strncat(buffer, "buzz", bufLen);
    } else {
      //can only do numbers upto 10^9
      char str[10];
      snprintf(str, sizeof(str), "%d", i);
      strncat(buffer, str, bufLen);
    }
    if (i < maxNum){
      strncat(buffer, ", ", bufLen);
    }
  }
  strncat(buffer, ".", bufLen);
}

void fizzbuzz_print(int maxNum){
  for (int i = 1; i <= maxNum; i++){
    if (i % 15 == 0){
      puts("fizzbuzz");
    }else if (i % 3 == 0){
      puts("fizz");
    } else if (i % 5 == 0){
      puts("buzz");
    } else {
      printf("%d\n", i);
    }
  }
}