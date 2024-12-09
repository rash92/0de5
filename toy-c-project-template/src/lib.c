int add(int a, int b) {
  return a + b;
}

char *fizzbuzz_p(int maxNum){

}

int fizzbuzz_buf(char buffer, int bufLen, int maxNum){
  for (int i=0; i<maxNum; i++){

  }
}

int fizzbuzz_print(int maxNum){
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