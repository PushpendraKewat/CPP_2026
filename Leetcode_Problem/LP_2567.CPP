// 2567. Minimum Score by Changing Two Elements
class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int low_score = 0;
        int high_score = INT_MAX;

        high_score = min(high_score, nums[n - 1] - nums[2]);
        high_score = min(high_score, nums[n - 2] - nums[1]);
        high_score = min(high_score, nums[n - 3] - nums[0]);

        int min_score = low_score + high_score;

        return min_score;
    }
};
