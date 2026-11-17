class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        int INF = 1e9;

        vector<vector<int>> cost(n, vector<int>(n, INF));
        // Step 1: Precompute substring costs
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int len = j - i + 1;

                for (int d = 1; d < len; d++) {
                    if (len % d != 0) continue;

                    int changes = 0;
                    int groups = len / d;

                    for (int x = 0; x < d; x++) {
                        for (int y = 0; y < groups / 2; y++) {
                            int left = i + x + y * d;
                            int right = i + x + (groups - 1 - y) * d;

                            if (s[left] != s[right]) {
                                changes++;
                            }
                        }
                    }

                    cost[i][j] = min(cost[i][j], changes);
                }
            }
        }

        // Step 2: DP
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, INF));
        dp[0][0] = 0;

        for (int i = 1; i <= k; i++) {
            for (int j = 2 * i; j <= n; j++) {
                for (int x = 2 * (i - 1); x <= j - 2; x++) {
                    dp[i][j] = min(dp[i][j],dp[i - 1][x] + cost[x][j - 1]);
                }
            }
        }

        return dp[k][n];
    }
};