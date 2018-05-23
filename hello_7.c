#include<stdio.h>
#include<string.h>

struct fraction {
      int number;
      int denom;
  };

int main(void){
  struct fraction a,b,c;
  a.number = 10;
  a.denom = 9;
  b.number = 5;
  b.denom = 6;
  c.number = a.number * a.number;
  c.denom = a.denom * b.denom;
}