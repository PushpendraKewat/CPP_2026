// methon 2 dp memoziation
class Solution {
public:
    int helper(int i, vector<int>& coins, int amount,
               vector<vector<int>>& dp) {

        if (amount == 0) return 0;
        if (i == coins.size()) return 1e9;

        if (dp[i][amount] != -1) return dp[i][amount];

        int take = 1e9;
        if (coins[i] <= amount) {
            take = 1 + helper(i, coins, amount - coins[i], dp);
        }

        int leave = helper(i + 1, coins, amount, dp);

        return dp[i][amount] = min(take, leave);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));

        int ans = helper(0, coins, amount, dp);

        return ans >= 1e9 ? -1 : ans;
    }
};

// method 1 recusrion
class Solution {
public:
    int helper(int i, int amount, vector<int>& coins) {
        if (amount == 0) return 0;
        if (i == coins.size()) return 1e9;

        if (amount - coins[i] < 0) {
            return helper(i + 1, amount, coins);
        }

        int take = 1 + helper(i, amount - coins[i], coins);
        int leave = helper(i + 1, amount, coins);

        return min(take, leave);
    }

    int coinChange(vector<int>& coins, int amount) {
        int ans = helper(0, amount, coins);
        return ans >= 1e9 ? -1 : ans;
    }
};