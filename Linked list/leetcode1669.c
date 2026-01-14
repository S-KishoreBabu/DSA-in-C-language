#include <stdio.h>
#include <stdlib.h>

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    
}

int main() {
    int nums[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int numsSize = 8;
    int k = 3;

    int returnSize = 0;
    int* result = maxSlidingWindow(nums, numsSize, k, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}
