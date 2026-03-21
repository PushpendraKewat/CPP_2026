#include<iostream>
#include<vector>
#include<algorithm>

using std::cout;
using std::endl;
using std::vector;

void solve(int idx, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans){
    ans.push_back(temp);

    for(int i = idx; i < nums.size(); i++){
        // skip duplicates
        if(i > idx && nums[i] == nums[i-1]) continue;

        temp.push_back(nums[i]);
        solve(i + 1, nums, temp, ans);
        temp.pop_back(); // backtrack
    }
}

int main(){
    vector<int> nums = {1,2,2};

    std::sort(nums.begin(), nums.end()); 

    vector<vector<int>> ans;
    vector<int> temp;

    solve(0, nums, temp, ans);

    for(auto v : ans){
        cout<<"[ ";
        for(int x : v) cout<<x<<" ";
        cout<<"]"<<endl;
    }

    return 0;
}