#include<iostream>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos = 0;
        int neg = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 0) neg++;
            else if(nums[i] > 0) pos++; // ignore zero
        }

        return std::max(pos, neg);
    }
};