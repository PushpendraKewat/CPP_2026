#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int ones = 0;
        int mxones = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) {
                ones++;
                mxones = max(mxones, ones);
            }
            else {
                ones = 0;
            }
        }

        return mxones;
    }
};