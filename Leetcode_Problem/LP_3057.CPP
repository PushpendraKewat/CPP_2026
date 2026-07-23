class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int operations = 0;

        while (true) {
            // Check if array is non-decreasing
            bool sorted = true;
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] < nums[i - 1]) {
                    sorted = false;
                    break;
                }
            }

            if (sorted) return operations;

            // Find leftmost adjacent pair with minimum sum
            int idx = 0;
            int minSum = nums[0] + nums[1];

            for (int i = 1; i < nums.size() - 1; i++) {
                int sum = nums[i] + nums[i + 1];
                if (sum < minSum) {
                    minSum = sum;
                    idx = i;
                }
            }

            // Merge the pair
            nums[idx] = minSum;
            nums.erase(nums.begin() + idx + 1);

            operations++;
        }
    }
};