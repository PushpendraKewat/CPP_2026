#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;

bool helper(int i, vector<int>& v, int target, vector<vector<int>>& dp){
    if(target == 0) return true;

    if(i >= v.size() || target < 0){
        return false;
    }

    if(dp[i][target] != -1){
        return dp[i][target];
    }

    bool take = helper(i + 1, v, target - v[i], dp);
    bool notTake = helper(i + 1, v, target, dp);

    return dp[i][target] = take || notTake;
}

int main(){
    vector<int> v = {2,4,1,2,6,3};
    int target = 8;

    int n = v.size();

    vector<vector<int>> dp(n, vector<int>(target + 1, -1));

    cout << helper(0, v, target, dp) << endl;

    return 0;
}