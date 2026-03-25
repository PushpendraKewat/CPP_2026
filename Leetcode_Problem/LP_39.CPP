#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    void helper(vector<int>& candidates, int target, int idx,
                vector<int>& curr, vector<vector<int>>& ans) {

        // base case
        if(target == 0){
            ans.push_back(curr);
            return;
        }

        if(target < 0 || idx == candidates.size()) return;

        //  include
        curr.push_back(candidates[idx]);
        helper(candidates, target - candidates[idx], idx, curr, ans);
        curr.pop_back(); // backtrack

        //  exclude
        helper(candidates, target, idx + 1, curr, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;

        helper(candidates, target, 0, curr, ans);

        return ans;
    }
};