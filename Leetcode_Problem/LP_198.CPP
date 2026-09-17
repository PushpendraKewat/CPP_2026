
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }
        vector<int> dp(n, 0);

        // Base cases
        dp[0] = nums[0];  // Robbing only the first house
        dp[1] = max(nums[0], nums[1]);  // Robbing either the first or second house, whichever gives more

        // Fill the dp array based on the recurrence relation
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        }

        // The result will be in the last position of the dp array
        return dp[n - 1];
    }
};
