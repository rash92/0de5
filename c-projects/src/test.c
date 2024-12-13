#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "lib.c"

// Very small test helpers
int failed = 0;
#define TEST(name) void name()
#define RUN_TEST(name) printf("\n\033[1m%s\n\033[0m", #name); name()
#define ASSERT(expr) if (!(expr)) { \
  failed = 1; \
  printf("\033[0;31mFAIL: %s\n\033[0m", #expr); \
} else { \
  printf("\033[0;32mPASS: %s\n\033[0m", #expr); \
}
#define ASSERT_STR_EQ(str1, str2) if (!(strcmp(str1, str2) == 0)) { \
  failed = 1; \
  printf("\033[0;31mFAIL: %s != %s\n\033[0m", str1, str2); \
} else { \
  printf("\033[0;32mPASS: %s == %s\n\033[0m", str1, str2); \
}
// End of test helpers

TEST(test_add) {
  ASSERT(add(1, 2) == 3);
  ASSERT(add(0, 0) == 0);
  ASSERT(add(-1, -1) == -2);
}

TEST(test_string_assert) {
  ASSERT_STR_EQ("hello", "hello");
}

TEST(test_wordify){
  char buffer[100] = {""};
  wordify(buffer, 100, 100);
  ASSERT_STR_EQ(buffer, "one hundred");
  wordify(buffer, 100, 20);
  ASSERT_STR_EQ(buffer, "twenty");
  wordify(buffer, 100, 10);
  ASSERT_STR_EQ(buffer, "ten");
  wordify(buffer, 100, 50);
  ASSERT_STR_EQ(buffer, "fifty");
  wordify(buffer, 100, 1523);
  ASSERT_STR_EQ(buffer, "one thousand five hundred and twenty three");
  wordify(buffer, 100, 13);
  ASSERT_STR_EQ(buffer, "thirteen");
  wordify(buffer, 100, 1000000);
  ASSERT_STR_EQ(buffer, "one million");
  wordify(buffer, 100, 15);
  ASSERT_STR_EQ(buffer, "fifteen");
  wordify(buffer, 100, 12);
  ASSERT_STR_EQ(buffer, "twelve");
  wordify(buffer, 100, 11);
  ASSERT_STR_EQ(buffer, "eleven");
  wordify(buffer, 100, 19);
  ASSERT_STR_EQ(buffer, "nineteen");

}

int main() {
  // Add a `RUN_TEST` line for each test function
  RUN_TEST(test_add);
  RUN_TEST(test_string_assert);
  RUN_TEST(test_wordify);
  return failed;
}
