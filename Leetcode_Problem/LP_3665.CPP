//   3665. Twisted Mirror Path Count

// 3d dp 
class Solution {
    int m, n;
    const int mod = 1e9 + 7;

    // d = 0 -> entered while moving right
    // d = 1 -> entered while moving down
    vector<vector<vector<int>>> dp;

    int help(vector<vector<int>>& grid, int r, int c, int d) {

        if (r >= m || c >= n) return 0; // out of boundary
        if (r == m - 1 && c == n - 1) return 1; 

        if (dp[r][c][d] != -1) return dp[r][c][d];

        // If the current cell contains a mirror, reflect the robot.
        if (grid[r][c] == 1) {
            // Entered while moving right -> turn down.
            if (d == 0) return dp[r][c][d] = help(grid, r + 1, c, 1);
            // Entered while moving down -> turn right.
            else return dp[r][c][d] = help(grid, r, c + 1, 0);
        }
        return dp[r][c][d] = (
            (long long)help(grid, r + 1, c, 1) +
            help(grid, r, c + 1, 0)
        ) % mod;
    }

public:
    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        dp.assign(m, vector<vector<int>>(n, vector<int>(2, -1)));

        return help(grid, 0, 0, 0);
    }
};

// method 1 brute force 
class Solution {
public:
    const int MOD = 1000000007;
    int solve(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();

        if (i >= m || j >= n) return 0;

        if (i == m - 1 && j == n - 1) return 1;

        long long ans = 0;

        // Move right
        int x = i, y = j + 1;

        while (x < m && y < n && grid[x][y] == 1) {
            x++;
        }

        if (x < m && y < n) {
            ans += solve(grid, x, y);
        }

        // Move down
        x = i + 1;
        y = j;

        while (x < m && y < n && grid[x][y] == 1) {
            y++;
        }

        if (x < m && y < n) {
            ans += solve(grid, x, y);
        }

        return ans % MOD;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        return solve(grid, 0, 0);
    }
};