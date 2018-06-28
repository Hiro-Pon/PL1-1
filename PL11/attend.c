#include <stdio.h>

unsigned int addtwo(unsigned int a){
  return a + 2;
}


unsigned int subtwo(unsigned int a){
  return a - 2;
}


int main(void){
  unsigned int (*p[1])(unsigned int) = {addtwo(unsigned int),subtwo(unsigned int)};
  printf("addtwo : %u \n", p[0](4) );
  printf("subtwo : %u \n", p[1](4) );
}
