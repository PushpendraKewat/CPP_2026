// 40. Combination Sum II
class Solution {
public:
    void helper(vector<int>& candidates, int target, int idx,vector<vector<int>>& ans, vector<int>& curr) {

        // base case
        if(target == 0){
            ans.push_back(curr);
            return;
        }

        for(int i = idx; i < candidates.size(); i++){

            // skip duplicates
            if(i > idx && candidates[i] == candidates[i-1]) continue;

            // pruning // not pick
            if(candidates[i] > target) break;

            // pick
            curr.push_back(candidates[i]);

            helper(candidates, target - candidates[i], i + 1, ans, curr);

            curr.pop_back(); // backtrack
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;

        sort(candidates.begin(), candidates.end());

        helper(candidates, target, 0, ans, curr);

        return ans;
    }
};