int maxSubArray(int* nums, int numsSize) {
    if(numsSize == 0) return 0;
    
    int curr_max = nums[0];
    int glob_max = nums[0];
    
    for(int i = 1; i < numsSize; i++) {
        curr_max = (nums[i] > curr_max + nums[i]) ? nums[i] : curr_max + nums[i];
        if(curr_max > glob_max) glob_max = curr_max;
    }
    return glob_max;
}
