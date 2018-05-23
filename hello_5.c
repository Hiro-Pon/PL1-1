#include <stdio.h>
#include <stdlib.h>

int *init_nums(int);
int count_even(int *, int);

int main() {
    int n = 17661;
    // allocate and initialize nums
    int *nums = init_nums(n);

    // print the number of even numbers in nums
    int x = count_even(nums, n);
    printf("%d\n", x);
}

int count_even(int *nums, int len) {
    int result;
    for(int i=0; i < len; i++) {
      if (nums[i] % 2 == 0) {
        result ++;
      }
    }
    return result;
}

int * init_nums(int len) {
    srandom(len);
    int *nums = malloc(sizeof(nums[0])*len);
    for (int i=0; i < len; i++) {
        nums[i] = random();
    }
    return nums;
}

