#include<iostream>
#include<vector>
#include<algorithm>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        for (int i = 0; i < n; i += 3) {
            // if triplet breaks or unique is at the end
            if (i + 1 >= n || nums[i] != nums[i + 1]) {
                return nums[i];
            }
        }
        return -1;
    }
};