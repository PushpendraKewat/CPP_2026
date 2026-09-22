class Solution {
public:
    int minDistance(string a, string b) {
        int m = a.size(), n = b.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0) {
                    dp[i][j] = j;  // If a is empty, we need to insert all characters of b
                } else if (j == 0) {
                    dp[i][j] = i;  // If b is empty, we need to remove all characters of a
                } else if (a[i - 1] == b[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];  // No operation needed
                } else {
                    int add = 1 + dp[i][j - 1];      // Insert
                    int remove = 1 + dp[i - 1][j];   // Remove
                    int replace = 1 + dp[i - 1][j - 1]; // Replace
                    dp[i][j] = min({add, remove, replace});
                }
            }
        }

        return dp[m][n];  // Minimum edit distance for a and b
    }
};
