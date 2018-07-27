#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define SIZE 10
#define Block 64
#define N (Block * SIZE)

int Random( int minvalue, int maxvalue ){
  static int RAND_SEED_FLAG;
  if (RAND_SEED_FLAG == 0){
    srand((unsigned int)time(NULL));
    RAND_SEED_FLAG = 1;

  }
   return minvalue + (int)(rand()*(maxvalue - minvalue + 1.0)/(1.0 + RAND_MAX));
}

double* create_matrix(){
  double* A = malloc(sizeof(double)*N*N);
  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      A[i + N*j] = Random(-20, 20);
    }
  }
  return A;
}

void print(double* A){
  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      printf("%lf, ", A[i + N*j]);
    }
    printf("\n");
 }
}

double* matmul1(double* A, double *B){
  double* C = malloc(sizeof(double)*N*N);
  clock_t start, end;

  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      C[i + N*j] = 0.0;
    }
  }

  start = clock();

  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      for (int k = 0; k < N; k++){
        C[i+ N*k] += A[i+N*j]*B[j+N*k];
      }
    }
  }

  end = clock();
  printf("matmul1: Excution Time: %lf [sec]\n", (double)(end - start)/CLOCKS_PER_SEC);

  return C;
}

double* matmul2(double* A, double *B){
  double* C = malloc(sizeof(double)*N*N);
  clock_t start, end;

  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      C[i + N*j] = 0.0;
    }
  }

  start = clock();

  for (int k = 0; k < N; k++){
    for (int j = 0; j < N; j++){
      for (int i = 0; i < N; i++){
        C[i+ N*k] += A[i+N*j]*B[j+N*k];
      }
    }
  }

  end = clock();
  printf("matmul1: Excution Time: %lf [sec]\n", (double)(end - start)/CLOCKS_PER_SEC);

  return C;
}


double* matmul3(double* A, double *B){
  double* C = malloc(sizeof(double)*N*N);
  clock_t start, end;

  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      C[i + N*j] = 0.0;
    }
  }

  start = clock();
  //#paragma omp parallel for
  for (int k = 0; k < N; k++){
    for (int j = 0; j < N; j++){
      for (int i = 0; i < N; i++){
        C[i+ N*k] += A[i+N*j]*B[j+N*k];
      }
    }
  }

  end = clock();
  printf("matmul1: Excution Time: %lf [sec]\n", (double)(end - start)/CLOCKS_PER_SEC);

  return C;
}

double* matmul4(double* A, double *B){
  double* C = malloc(sizeof(double)*N*N);
  clock_t start, end;

  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      C[i + N*j] = 0.0;
    }
  }

  start = clock();
  printf("AA\n");
  for (int k = 0; k < N; k++){
    for (int j = 0; j < N; j+= 4){
      int j1 = j + 1;
      int j2 = j + 2;
      int j3 = j + 3;
      int j4 = j + 4;
      for (int i = 0; i < N; i += 4){
        int i1 = i + 1;
        int i2 = i + 2;
        int i3 = i + 3;
        int i4 = i + 4;
        C[i1+ N*k] += A[i1+N*j1]*B[j1+N*k];
        C[i2+ N*k] += A[i2+N*j1]*B[j1+N*k];
        C[i3+ N*k] += A[i3+N*j1]*B[j1+N*k];
        C[i4+ N*k] += A[i4+N*j1]*B[j1+N*k];

        C[i1+ N*k] += A[i1+N*j2]*B[j2+N*k];
        C[i2+ N*k] += A[i2+N*j2]*B[j2+N*k];
        C[i3+ N*k] += A[i3+N*j2]*B[j2+N*k];
        C[i4+ N*k] += A[i4+N*j2]*B[j2+N*k];

        C[i1+ N*k] += A[i1+N*j3]*B[j3+N*k];
        C[i2+ N*k] += A[i2+N*j3]*B[j3+N*k];
        C[i3+ N*k] += A[i3+N*j3]*B[j3+N*k];
        C[i4+ N*k] += A[i4+N*j3]*B[j3+N*k];

        C[i1+ N*k] += A[i1+N*j4]*B[j3+N*k];
        C[i2+ N*k] += A[i2+N*j4]*B[j3+N*k];
        C[i3+ N*k] += A[i3+N*j4]*B[j3+N*k];
        C[i4+ N*k] += A[i4+N*j4]*B[j3+N*k];
      }
    }
  }
  printf("BB\n");

  end = clock();
  printf("matmul1: Excution Time: %lf [sec]\n", (double)(end - start)/CLOCKS_PER_SEC);

  return C;
}


int main(void){
  double* A = create_matrix();
  double* B = create_matrix();

//  print(A);
//  print(B);

  double* C1 = matmul1(A, B);

  double* C2 = matmul2(A, B);

  double* C3 = matmul4(A, B);
  if (C1 == C2) {
    printf("OK\n");
  }

  free(A);
  free(B);
  free(C1);
  free(C2);
  free(C3);
}
