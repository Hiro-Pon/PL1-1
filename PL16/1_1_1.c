#include <stdio.h>
#include <stdlib.h>


char to_bit(unsigned int num){
  char tmp[32];
  for (int i = 0; i < 32; i++) {
    tmp[i] = num % 2;
    num = num / 2;
  }

  for (int i = 32; i > -1; i--) {
    /* code */
    printf("%d", tmp[i]);
  }
  printf("\n");
}

int main() {
  to_bit(5);
}
