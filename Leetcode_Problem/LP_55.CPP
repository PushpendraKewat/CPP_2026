// method 3 greedy approach
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(i > maxReach) {
                return false;
            }

            maxReach = max(maxReach, i + nums[i]);
        }

        return true;
    }
};

// method 2 tabulation 
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        vector<bool> dp(n, false);
        dp[n - 1] = true;

        for(int i = n - 2; i >= 0; i--){
            for(int jump = 1; jump <= nums[i] && i + jump < n; jump++){
                if(dp[i + jump]){
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[0];
    }
};

// method 1 memoziation
class Solution {
public:
    bool helper(int idx, vector<int>& nums, vector<int>& dp){
        int n = nums.size();

        if(idx >= n - 1) return true;

        if(dp[idx] != -1) return dp[idx];

        for(int i = 1; i <= nums[idx]; i++){
            if(helper(idx + i, nums, dp)){
                return dp[idx] = true;
            }
        }

        return dp[idx] = false;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        return helper(0, nums, dp);
    }
};