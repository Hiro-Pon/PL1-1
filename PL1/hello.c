#include <stdio.h>
int main() {                   
    int n = 10;
    int *F;
    int tem = n;
    F = malloc(sizeof(int)*n);
    F[0] = 0;
    F[1] = 1;
    for (int i = 2;i - n - 2;i++){
        F[i] = F[i-1] + F[i-2];
        printf("%d\n",F[i]);
    }
    free(F);
}