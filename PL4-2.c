#include<stdio.h>
#include<stdlib.h>

struct fraction{
  int numer;
  int denom;
};

struct fraction mul(struct fraction a,struct fraction b ) {
  struct fraction c;
  c.numer = a.numer * b.numer;
  c.denom = a.denom * b.denom;
  return c;
}

void print(struct fraction x){
  printf("%d / %d\n",x.numer,x.denom);
}

struct fraction add(struct fraction a,struct fraction b ) {
  struct fraction c;
  //通分
  a.numer = a.numer * b.denom;
  b.numer = b.numer * a.denom;

  a.denom = a.denom * b.denom;
  b.denom = a.denom;
  print(a);
  print(b);

  //加算
  c.numer = a.numer + b.numer;
  c.denom = a.denom;
  return c;
}

struct fraction subs(struct fraction a,struct fraction b ) {
  struct fraction c;
  //通分
  a.numer = a.numer * b.denom;
  b.numer = b.numer * a.denom;

  a.denom = a.denom * b.denom;
  b.denom = a.denom;
  print(a);
  print(b);

  //引き算
  c.numer = a.numer - b.numer;
  c.denom = a.denom;
  return c;
}

struct fraction div(struct fraction a,struct fraction b ) {
  int pre;
  b.denom = b.numer;
  b.numer = b.denom;
  
  return mul(a,b);
}


int main(void){
  struct fraction a , b ;
  a.numer = 2;
  a.denom = 3;
  b.numer = 1;
  b.denom = 2;
  print(add(a,b));
}