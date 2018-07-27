#include <stdlib.h>
#include <stdio.h>
#define n 10*1024
typedef struct {
  double a[n], w[n][n], v[n];
} arrays_t;

void func(double a[n], double w[][n], double v[n], int start, int end) {
  for(long i=start; i < end/2; i++) {
    for(long j=0; j < n; j++) {
      a[i] += w[i][j]*v[j];
      a[n-i] += w[n-i][j]*v[j];
    }
  }
}


int main() {
  arrays_t *a = malloc(sizeof(*a));
  func(a->a, a->w, a->v, 0, n);
  printf("a %f\n", a->a[n/2]);
}
