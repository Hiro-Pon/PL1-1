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

        A.i = 365779719;
                                
        t.s = A.t[0].s;
        A.t[0].s = A.t[1].s;
        A.t[1].s = t.s;
        t.c[0] = A.t[0].c[0];
        A.t[0].c[0] = A.t[1].c[1];
        A.t[1].c[1] = t.c[0];

        printf("%d\n",A.i);

        union crypt B;
        union tmp T;

        B.i = 1528104909;

        T.c[0] = B.t[1].c[1] ;
        B.t[1].c[1] = B.t[0].c[0];
        B.t[0].c[0] = T.c[0];
        T.s = B.t[1].s ;
        B.t[1].s = B.t[0].s;
        B.t[0].s = T.s;

        printf("%d\n",A.i);

}