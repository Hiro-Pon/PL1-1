#define DEBUG

#include <stdio.h>
#include "com.h"
#include "com.h"

#define CPRINT(A) printf("%lf + i %lf\n", A.real, A.imag);

int main(void){
  cmplx a = {1.0, 2.0};
  cmplx b = {3.0, 4.0};

  cmplx c = mul_cmplx(a, b);
  printf("%lf + i %lf\n", c.real, c.imag);

}
