#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int i = 0;

        while(i < n){
            int correctidx = nums[i];

            if(nums[i] < n && nums[i] != nums[correctidx]){
                std::swap(nums[i], nums[correctidx]);
            }
            else{
                i++;
            }
        }

        for(int i = 0; i < n; i++){
            if(nums[i] != i){
                return i;
            }
        }

        return n;
    }
};