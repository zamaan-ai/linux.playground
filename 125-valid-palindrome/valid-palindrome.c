bool isPalindrome(char *s) {
    int left = 0, right = strlen(s) - 1;
    
    while (left < right) {
        // Skip non-alphanumeric left
        while (left < right && !isalnum(s[left])) left++;
        // Skip non-alphanumeric right  
        while (left < right && !isalnum(s[right])) right--;
        
        // Compare ignoring case
        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}
