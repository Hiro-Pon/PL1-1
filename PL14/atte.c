#define n 128
volatile double a[n];

inline void func(double w[][n], double v[n]) {
  for(long i=0; i < n; i++) {
    for(long j=0; j < n; j++) {
      a[i] += w[i][j]*v[j];
    }
  }
}

int main() {
  double w[n][n], v[n];
  func(w, v);
}
