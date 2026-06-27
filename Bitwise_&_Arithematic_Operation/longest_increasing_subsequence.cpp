#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;

int lis(vector<int>& nums){
    int n = nums.size();
    int ans = 1;
    vector<int> dp(n,1);

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[i]>nums[j]){
                dp[i] = std::max(dp[i],dp[j]+1);
            }
        }
        ans = std::max(ans,dp[i]);
    }
    return ans;
}

int main(){
    vector<int> nums {10,9,2,5,3,7,101,18};
    cout<<lis(nums);
    return 0;
}