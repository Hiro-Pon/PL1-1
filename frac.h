#include<stdio.h>
#include<stdlib.h>

struct fraction{
  int numer;
  int denom;
};

void print(struct fraction x){
  printf("%d / %d\n",x.numer,x.denom);
}