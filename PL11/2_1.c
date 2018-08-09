#include <stdio.h>
#include <math.h>

double my_exp(double x, int n){
  double ans,tmp;

  ans=x;
  tmp=x;
  for(int i=1;i<n;i++){
    tmp=tmp*(-1)*x*x/((2.0*i)*(2.0*i+1.0));
    ans=ans+tmp;
  }

  return ans;
}

int main(void){
  int n = 100;
  double x = 20.0;
  printf("my_exp(%lf) = %lf \n", x, my_exp(x, n));
  printf("exp(%lf) = %lf \n", x, exp(x));
}
