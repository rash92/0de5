#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int add(int a, int b) {
  return a + b;
}

char *fizzbuzz_pointer(int maxNum){
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

void fizzbuzz_buffer(char buffer[], size_t bufLen, int maxNum){
  for (int i = 1; i<= maxNum; i++){
    int check = 0;
    if (i % 15 == 0){
      check = snprintf(buffer, bufLen, "fizzbuzz, ");
    } else if (i%5 == 0){
      check = snprintf(buffer, bufLen, "buzz, ");

    } else if (1%3 == 0){
      check = snprintf(buffer, bufLen, "fizz, ");
    } else {
      check = snprintf(buffer, bufLen, "%d, ", i);
    }
    if (check < 0 || check > bufLen) {
      puts("buffer too small to contain answer string");
      return;
    }
    buffer += check;
    bufLen -= check;
  }
  buffer -= 2;
  bufLen -= 2;

  snprintf(buffer, bufLen, ".");

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

int prime_sieve(int *ansBuffer, int upto){
  int numElems = upto-1;
  int all_nums[numElems];

  // create array with all nums from 2 to n
  for (int i=2; i<=upto; i++){
    all_nums[i-2] = i;
  }
  
  // remove elements that are multiples of the first element, except the first element itself.
  for (int startIndex = 0; startIndex < numElems; startIndex++){
    int currentCheck = all_nums[startIndex];
    if (currentCheck == 0){
      continue;
    }
    for (int i=startIndex+1; i<numElems; i++ ){
      if (all_nums[i] % currentCheck == 0 && all_nums[i] != 0){
        all_nums[i] = 0;
      }
    }
  }
  
  //add ans to buffer passed in by checking for zeros
  int bufCounter = 0;
  for (int i=0; i< numElems; i++){
    if (all_nums[i] != 0){
      ansBuffer[bufCounter] = all_nums[i];
      bufCounter++;
    }
  }

  return bufCounter;
}

void wordify(char buffer[], int bufLen, int number){
  // single digit to string
  char *digitWords[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
  char *tensWords[] = {"", "ten", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};
  // last two digits

  int lastDigit = number % 10;
  int secondLastDigit = (number % 100 - lastDigit)/10;
  bool endIn0 = false;
  bool endIn00 = false;
  bool teen = false;
  
  if (lastDigit == 0) endIn0 = true;
  if (lastDigit == 0 && secondLastDigit == 0) endIn00 = true;
  if (secondLastDigit == 1 && lastDigit != 0) teen = true;
  char suffix[10] = {0};

  // teens case
  if (teen){
    if (lastDigit == 1){
      snprintf(suffix,10, "eleven");
    } else if (lastDigit == 2){
      snprintf(suffix,10, "twelve");
    } else if (lastDigit == 3){
      snprintf(suffix,10, "thirteen");
    } else if (lastDigit == 5){
      snprintf(suffix, 10, "fifteen");
    } else{
      strncat(suffix, digitWords[lastDigit], 10);
      strncat(suffix, "teen", 10);
    }
  }

  // tens case
  if (endIn0){
    snprintf(suffix, 10, tensWords[secondLastDigit]);
  }

  int numDigits = 0;
  if ((endIn0 || teen) && number / 100 == 0){
    snprintf(buffer, bufLen, suffix);
    return;
  }
  
  return;
}