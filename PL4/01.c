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

struct fraction divs(struct fraction a,struct fraction b ) {
  int pre;
  pre = b.denom;
  b.denom = b.numer;
  b.numer = pre;

  return mul(a,b);
}

int main(void){
  struct fraction e , f ;
  e.numer = 2;
  e.denom = 2;
  f.numer = 3;
  f.denom = 3;
  print(mul(e,f));
}
