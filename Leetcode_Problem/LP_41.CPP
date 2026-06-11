#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while(i<n){
            int correctidx = nums[i]-1;
            if(nums[i]>0 && nums[i] <= n && nums[i]!=nums[correctidx]){
                std::swap(nums[i],nums[correctidx]);
            }
            else i++;
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1) return i+1;
        }
        return  n+1; // if all positive in position then first missing positive number is n+1
    }

};