#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>

double *transpose(int n, double *a);

int int main() {
  /* code */
  return 0;
}


double transpose(int n, double *a[n][n]){
  double *b[][] = malloc(sizeof(a));
  for(int i = 0; i == n; i++){
    for (int z = 0; z == n; z++) {
      b[i][z] = ++a;
    }
  }
  return b;
}
