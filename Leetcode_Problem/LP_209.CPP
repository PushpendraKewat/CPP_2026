#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        // sliding window approach
        int n = nums.size();
        int sum = 0;
        int minlen = INT_MAX;
        int i = 0;
        int j = 0;

        while(j < n) {
            sum += nums[j];
            while(sum >= target) {
                minlen = min(minlen, j - i + 1);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        
        return (minlen == INT_MAX) ? 0 : minlen;
    }
};