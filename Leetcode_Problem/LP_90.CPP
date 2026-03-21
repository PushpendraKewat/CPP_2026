#include<iostream>
#include<vector>
#include<algorithm>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    void helper(int idx, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans){
        ans.push_back(temp);
        for(int i = idx ; i<nums.size();i++){
            // skip
            if(i>idx && nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            helper(i+1,nums,temp,ans);
            temp.pop_back(); // backtrack
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::sort(nums.begin(),nums.end()); // very important
        vector<int> temp;
        vector<vector<int>> ans;
        helper(0,nums,temp,ans);
        return ans;
    }
};