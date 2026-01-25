int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
*returnSize = 0;
    if (numsSize < 3) return NULL;

    // 1. Sort the input array
    qsort(nums, numsSize, sizeof(int), compare);

    // Initial allocation for result pointers
    int capacity = 1000; 
    int** result = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));

    for (int i = 0; i < numsSize - 2; i++) {
        // Skip duplicate values for the first element
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int low = i + 1;
        int high = numsSize - 1;

        while (low < high) {
            int sum = nums[i] + nums[low] + nums[high];

            if (sum == 0) {
                // Found a triplet
                result[*returnSize] = (int*)malloc(3 * sizeof(int));
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[low];
                result[*returnSize][2] = nums[high];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                // Expand capacity if needed
                if (*returnSize == capacity) {
                    capacity *= 2;
                    result = (int**)realloc(result, capacity * sizeof(int*));
                    *returnColumnSizes = (int*)realloc(*returnColumnSizes, capacity * sizeof(int));
                }

                // Skip duplicates for low and high pointers
                while (low < high && nums[low] == nums[low + 1]) low++;
                while (low < high && nums[high] == nums[high - 1]) high--;

                low++;
                high--;
            } else if (sum < 0) {
                low++;
            } else {
                high--;
            }
        }
    }
    return result;
}