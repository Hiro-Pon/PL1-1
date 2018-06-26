#include<stdio.h>
#include<stdlib.h>
#include"frac.h"

struct fraction mul(struct fraction a,struct fraction b ) {
  struct fraction c;
  c.numer = a.numer * b.numer;
  c.denom = a.denom * b.denom;
  return c;
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
  pre = b.denom
  b.denom = b.numer;
  b.numer = pre
  
  return mul(a,b);
}


struct fraction yakubun(struct fraction a) {
  while r != 1{
      if(a<b){
          tmp = a;
          a = b;
          b = tmp;
          }
        r = a % b;
        while(r!=0){
            a = b;
             b = r;
              r = a % b;
              }
  }
  
  return 
}