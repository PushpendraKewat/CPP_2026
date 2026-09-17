class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int m = arr.size();      // row   
        int n = arr[0].size();      // columns
        if (arr[0][0] == 1 || arr[m-1][n-1] == 1) return 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        dp[0][0] = 1;
        
        // Fill the DP table
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // If the current cell is an obstacle, skip it
                if (arr[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    if (i > 0) dp[i][j] += dp[i - 1][j]; // Add paths from the top
                    if (j > 0) dp[i][j] += dp[i][j - 1]; // Add paths from the left
                }
            }
        }
        
        // The answer is in the bottom-right corner
        return dp[m - 1][n - 1];
    }
};
