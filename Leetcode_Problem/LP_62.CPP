// method 4 space optimiztion 
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};


// method 3 dp tabulation
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 1;
                }
                else{
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};


// method 2 dp memoziation
class Solution {
public:
    int helper(int r, int c, int m, int n, vector<vector<int>>& dp){
        if(r >= m || c >= n) return 0;

        if(r == m - 1 && c == n - 1) return 1;

        if(dp[r][c] != -1) return dp[r][c];

        int rightways = helper(r, c + 1, m, n, dp);
        int downways = helper(r + 1, c, m, n, dp);

        return dp[r][c] = rightways + downways;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return helper(0, 0, m, n, dp);
    }
};

// method 1 recusrion
class Solution {
public:
    int helper(int sc, int ec, int sr, int er){
        if(sc > ec || sr > er) return 0;

        if(sc == ec && sr == er) return 1;

        int rightways = helper(sc + 1, ec, sr, er);
        int downways = helper(sc, ec, sr + 1, er);

        return rightways + downways;
    }

    int uniquePaths(int m, int n) {
        return helper(0, m - 1, 0, n - 1);
    }
};