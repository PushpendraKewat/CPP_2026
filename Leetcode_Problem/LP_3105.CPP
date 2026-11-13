// 3105. Longest Strictly Increasing or Strictly Decreasing Subarray
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int best = 1, up = 1, down = 1;

        for(int i = 1; i < nums.size(); i++) {
            up = nums[i] > nums[i - 1] ? up + 1 : 1;
            down = nums[i] < nums[i - 1] ? down + 1 : 1;

            best = max(best, max(up, down));
        }

        return best;
    }
};