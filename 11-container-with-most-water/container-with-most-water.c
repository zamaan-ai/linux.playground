int maxArea(int* height, int heightSize) {
    int left = 0, right = heightSize - 1;
    int max_area = 0;
    
    while(left < right) {
        int area = (height[left] < height[right] ? height[left] : height[right]) * (right - left);
        max_area = (area > max_area ? area : max_area);
        
        if(height[left] < height[right]) left++;
        else right--;
    }
    return max_area;
}