#ifndef INCLUDE_CMPLX_H
#define INCLUDE_CMPLX_H

#include <stdio.h>

typedef struct cmplx{
  double real;
  double imag;
} cmplx;

cmplx add_cmplx(struct cmplx a,struct cmplx b){
  cmplx d;
  d.real = a.real + b.real;
  d.imag = a.imag + b.imag;

  #ifdef DEBUG
  pprintf("%lf + i %lf\n", d.real, d.imag);
  #endif


  return d;
}

cmplx mul_cmplx(struct cmplx a,struct cmplx b){
  cmplx d;
  d.real = (a.real * b.real) - (a.imag * b.imag);
  d.imag = (a.real * b.real) + (a.imag * b.imag);

  #ifdef DEBUG
  pprintf("%lf + i %lf\n", d.real, d.imag);
  #endif

  return d;
}

#endif
