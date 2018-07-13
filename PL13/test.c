#define n 128
double a[n], w[n][n], v[n];

int main() {
  for(long i=0; i < n; i++) {
    for(long j=0; j < n; j++) {
      a[i] = w[i][j]*v[j];
    }
  }
}
