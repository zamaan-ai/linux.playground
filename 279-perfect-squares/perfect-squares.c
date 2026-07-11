int numSquares(int n) {
// Create a DP array to store the minimum squares for each number up to n
    int* dp = (int*)malloc((n + 1) * sizeof(int));
    
    // Initialize DP array with a maximum possible value
    for (int i = 0; i <= n; i++) {
        dp[i] = i; // The worst case is 1^2 + 1^2 + ... (n times)
    }
    
    // Fill the DP array
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j * j <= i; j++) {
            int square = j * j;
            if (dp[i - square] + 1 < dp[i]) {
                dp[i] = dp[i - square] + 1;
            }
        }
    }
    
    int result = dp[n];
    free(dp);
    return result;
}