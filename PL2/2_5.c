#include<stdio.h>

union tmp{
        short s;
        char c[2];
};
union crypt{
        int i;
        union tmp t[2];
};

int main(void){
        union crypt A;
        union tmp t;

        A.i = ??;

        t.s = A.t[0].s;
        A.t[0].s = A.t[1].s;
        A.t[1].s = t.s;
        t.c[0] = A.t[0].c[0];
        A.t[0].c[0] = A.t[1].c[1];
        A.t[1].c[1] = t.c[0];

        printf("%d\n",A.i);
        /*1528104909*/
}
