#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;

void subset(vector<int>& nums, int n, int idx, vector<int>& ans){
    if(idx == n){
        for(int x : ans){
            cout << x << " ";
        }
        cout << endl;
        return;
    }

    // exclude
    subset(nums, n, idx + 1, ans);

    // include
    ans.push_back(nums[idx]);
    subset(nums, n, idx + 1, ans);

    // backtrack (VERY IMPORTANT)
    ans.pop_back();
}

int main(){
    vector<int> nums = {1,2,3};
    vector<int> ans;

    subset(nums, nums.size(), 0, ans);

    return 0;
}