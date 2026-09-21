class Solution {
public:
    bool helper(int i, vector<int>& nums, vector<vector<int>>& dp, int target){
        if(target == 0) return true;
        if(i >= nums.size() || target < 0) return false;

        if(dp[i][target] != -1) return dp[i][target];

        bool take = helper(i + 1, nums, dp, target - nums[i]);
        bool notTake = helper(i + 1, nums, dp, target);

        return dp[i][target] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for(int i=0;i<n;i++){
            totalSum += nums[i];
        }
        if(totalSum%2!=0) return false; // if sum of array is odd then return false

        int target = totalSum/2;

        vector<vector<int>> dp(n, vector<int>(target+1, -1));

        return helper(0, nums, dp, target);
    }
};