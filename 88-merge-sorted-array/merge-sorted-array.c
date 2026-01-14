void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i = m - 1;  // nums1 end
    int j = n - 1;  // nums2 end
    int k = m + n - 1;  // final position
    
    // Merge backwards (no overwrite)
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }
    
    // Remaining nums2 elements
    while (j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}
