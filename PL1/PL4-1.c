#include<stdio.h>
#include<stdlib.h>



int Fibonacci(int n) {
  int prepre = 0;
  int pre = 1;
  int kari = 0;
  int now = 0;
  for (int i; i < n ; i++){
    kari = now;
    prepre = pre;
    pre = kari;
    now = pre + prepre;
  }

  return now;
}

int main(void){
  int a = Fibonacci(4);
  printf("%d\n",a);
  
}