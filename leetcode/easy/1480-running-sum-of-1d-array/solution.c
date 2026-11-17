#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize) {
    // 1. Set the size of the returned array
    *returnSize = numsSize;
    
    // 2. Allocate memory for the resulting running sum array
    int* result = (int*)malloc(numsSize * sizeof(int));
    if (result == NULL) {
        return NULL; // Safety check in case memory allocation fails
    }
    
    // 3. Initialize the first element
    result[0] = nums[0];
    
    // 4. Compute the prefix running sum iteratively
    for (int i = 1; i < numsSize; i++) {
        result[i] = result[i - 1] + nums[i];
    }
    
    return result;
}
