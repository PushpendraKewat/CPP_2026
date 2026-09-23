// method 2 tabulation
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for(int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }

        for(int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {

                if(word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    int insert = 1 + dp[i][j - 1];
                    int del = 1 + dp[i - 1][j];
                    int replace = 1 + dp[i - 1][j - 1];

                    dp[i][j] = min(insert, min(del, replace));
                }
            }
        }

        return dp[m][n];
    }
};

// METHOD 1 dp memoziation
class Solution {
public:
    int helper(string& a, string& b, int i, int j,
               vector<vector<int>>& dp) {

        if(i < 0) return j + 1;
        if(j < 0) return i + 1;

        if(dp[i][j] != -1) return dp[i][j];

        if(a[i] == b[j]) {
            return dp[i][j] = helper(a, b, i - 1, j - 1, dp);
        }

        int add = 1 + helper(a, b, i, j - 1, dp);
        int remove = 1 + helper(a, b, i - 1, j, dp);
        int replace = 1 + helper(a, b, i - 1, j - 1, dp);

        return dp[i][j] = min(add, min(remove, replace));
    }

    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return helper(word1, word2, m - 1, n - 1, dp);
    }
};