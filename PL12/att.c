#include <stdio.h>
#include <math.h>

void solve_quadratic_equation(double a, double b, double c, double *x1, double *x2){
  double D = b*b -4 * a * c; // 判別式
  if (D > 0) {
    *x1 = (-1 * b + sqrt(D)) / (2 * a);
    *x2 = (-1 * b - sqrt(D)) / (2 * a);
  }
  else if (D == 0) {
    *x1 = -b/(2.0*a);
    *x2 = *x1;
  }
  else {
    printf("This equation has no real number solution\n");
  }
}

int main(void){
  double a, b, c;
  double x1, x2;


  printf("a=");
  scanf("%lf",&a);

  printf("b=");
  scanf("%lf",&b);

  printf("c=");
  scanf("%lf",&c);

  printf("%lf  %lf  %lf\n",a,b,c );
  solve_quadratic_equation(a, b, c, &x1, &x2);
  printf("x1 = %19.17lf, x2 = %19.17lf\n", x1, x2);
}
