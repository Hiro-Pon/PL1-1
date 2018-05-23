#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int n = 17661;
    srandom(n);
    int *nums = malloc(sizeof(nums[0])* n );
    for (int i=0; i < n ; i++) {
        nums[i] = random();
    }
    // print the average of nums
    long x = 0;
    for (int i=0; i < n ; i++) {
        x += nums[i];
    }
    printf("%ld\n", x/n);
}