#include <stdio.h>

int main() {
    int a = 10;
    int b = 20;
    int r;
    int tmp;
    if(a<b){
        tmp = a;
        a = b;
        b = tmp;
    }
    /* ユークリッドの互除法 */
    r = a % b;
    while(r!=0){
        a = b;
        b = r;
        r = a % b;
    }   
    printf("%d\n",r);
}