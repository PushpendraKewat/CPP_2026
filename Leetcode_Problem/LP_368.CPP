class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {}; 
        
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        vector<int> prev(n, -1); 
        int maxSize = 1, maxIndex = 0;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j; // Store the index of the previous element
                }
            }
            if (maxSize < dp[i]) {
                maxSize = dp[i];
                maxIndex = i; // Update the index of the largest subset
            }
        }

        // Reconstruct the largest divisible subset
        vector<int> result;
        for (int i = maxIndex; i >= 0; ) {
            result.push_back(nums[i]);
            i = prev[i]; // Move to the previous index
        }
        reverse(result.begin(), result.end()); // Reverse to get the correct order
        
        return result;
    }
};