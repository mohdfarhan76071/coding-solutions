int search(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    
    while (left <= right) {
        // Calculate mid using this formula to avoid potential integer overflow
        int mid = left + (right - left) / 2;
        
        // Target found, return its index
        if (nums[mid] == target) {
            return mid;
        }
        // If target is larger, search the right half
        else if (nums[mid] < target) {
            left = mid + 1;
        }
        // If target is smaller, search the left half
        else {
            right = mid - 1;
        }
    }
    
    // Target does not exist in the array
    return -1;
}
