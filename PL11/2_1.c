#include <stdio.h>
#include <math.h>

double my_exp(double x, int n){
  double ans = 1.0, y = 1.0;

  for (float i = 1; i <= n; i++){
    for (float z = i; z != 0; z--){
      y = y *(x / z);
      printf("%lf/%lf\n", x,z);
    }
    ans += y;
  }

  return ans;
}

int main(void){
  int n = 100;
  double x = 20.0;
  printf("my_exp(%lf) = %lf \n", x, my_exp(x, n));
  printf("exp(%lf) = %lf \n", x, exp(x));
}
