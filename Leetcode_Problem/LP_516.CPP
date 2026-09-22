class Solution {
public:
    vector<vector<int>> dp;

    int solve(string& s, string& t, int i, int j) {
        if (i < 0 || j < 0) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (s[i] == t[j]) {
            return dp[i][j] = 1 + solve(s, t, i - 1, j - 1);
        }

        return dp[i][j] = max(
            solve(s, t, i - 1, j),
            solve(s, t, i, j - 1)
        );
    }

    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());

        int n = s.size();

        dp.resize(n, vector<int>(n, -1));

        return solve(s, t, n - 1, n - 1);
    }
};