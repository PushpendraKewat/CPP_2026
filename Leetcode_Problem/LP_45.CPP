// METHOD 2 DP MEMOZIATION
class Solution {
public:
    int helper(int idx, vector<int>& nums, vector<int>& dp) {
        int n = nums.size();

        if(idx >= n - 1) {
            return 0;
        }

        if(dp[idx] != -1) {
            return dp[idx];
        }

        int ans = 1e9;

        for(int jump = 1; jump <= nums[idx]; jump++) {
            ans = min(ans, 1 + helper(idx + jump, nums, dp));
        }

        return dp[idx] = ans;
    }

    int jump(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, -1);

        return helper(0, nums, dp);
    }
};

// METHOD 1 GREEDY
class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int currEnd = 0;
        int farthest = 0;

        for(int i = 0; i < nums.size() - 1; i++) {
            farthest = max(farthest, i + nums[i]);

            if(i == currEnd) {
                jumps++;
                currEnd = farthest;
            }
        }

        return jumps;
    }
};