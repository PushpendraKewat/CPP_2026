// 3882. Minimum XOR Path in a Grid

// method dp optimization
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int K = 1024;

        vector<vector<vector<bool>>> dp(
            m, vector<vector<bool>>(n, vector<bool>(K, false))
        );

        dp[0][0][grid[0][0]] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }

                for (int x = 0; x < K; x++) {
                    if (i > 0 && dp[i - 1][j][x]) {
                        dp[i][j][x ^ grid[i][j]] = true;
                    }

                    if (j > 0 && dp[i][j - 1][x]) {
                        dp[i][j][x ^ grid[i][j]] = true;
                    }
                }
            }
        }

        for (int x = 0; x < K; x++) {
            if (dp[m - 1][n - 1][x]) {
                return x;
            }
        }

        return 0;
    }
};

// brute force method 1 (time limit exced)
class Solution {
public:
    void solve(vector<vector<int>>& grid, int i, int j, int xr, int& ans) {
        int m = grid.size();
        int n = grid[0].size();

        xr ^= grid[i][j];

        if (i == m - 1 && j == n - 1) {
            ans = min(ans, xr);
            return;
        }

        // Move right
        if (j + 1 < n) {
            solve(grid, i, j + 1, xr, ans);
        }

        // Move down
        if (i + 1 < m) {
            solve(grid, i + 1, j, xr, ans);
        }
    }

    int minCost(vector<vector<int>>& grid) {
        int ans = INT_MAX;
        solve(grid, 0, 0, 0, ans);
        return ans;
    }
};