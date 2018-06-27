#include<stdio.h>
#include<stdlib.h>
#include"frac.h"
#include"frac.c"

int main(void){
  struct fraction a , b ;
  a.numer = 2;
  a.denom = 3;
  b.numer = 1;
  b.denom = 2;
  print(add(a,b));
}
