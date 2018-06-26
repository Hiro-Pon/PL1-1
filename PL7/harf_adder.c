#include <stdio.h>

int main() {
    int p1 = 1;
    int p2 = 1;
    harfadder(&p1,&p2);
    printf("\n %d,%d\n",p1,p2);
}

void harfadder(int* A ,int* B){
    int add_num = *A + *B;
    if (add_num == 0) {
        *A = 0;
        *B = 0;
    }else if (add_num == 1){
        *A = 0;
        *B = 1;
    }else {
        *A = 1;   
        *B = 1;
    }
}