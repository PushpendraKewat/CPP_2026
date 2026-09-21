class Solution {
public:
    int helper(int i, vector<int>& nums, int target,
               vector<vector<int>>& dp) {

        if(i == nums.size()){
            return target == 0;
        }

        if(dp[i][target] != -1){
            return dp[i][target];
        }

        int take = 0;
        if(nums[i] <= target){
            take = helper(i + 1, nums, target - nums[i], dp);
        }

        int notTake = helper(i + 1, nums, target, dp);

        return dp[i][target] = take + notTake;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;

        for(int i = 0; i < nums.size(); i++){
            totalSum += nums[i];
        }

        if(abs(target) > totalSum){
            return 0;
        }

        if((totalSum + target) % 2 != 0){
            return 0;
        }

        int subsetSum = (totalSum + target) / 2;

        vector<vector<int>> dp(nums.size(),
                               vector<int>(subsetSum + 1, -1));

        return helper(0, nums, subsetSum, dp);
    }
};