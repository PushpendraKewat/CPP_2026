#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>

using std::cout;
using std::endl;
using std::vector;

int longest_subarray(vector<int>& nums){
    int mx = INT_MIN;
    int count = 0;
    int ans = 0;

    for(int i = 0; i < nums.size(); i++){
        if(nums[i] > mx){
            mx = nums[i];
            count = 1;
            ans = 1;
        }
        else if(nums[i] == mx){
            count++;
            ans = std::max(ans, count);
        }
        else{
            count = 0;
        }
    }

    return ans;
}

int main(){
    vector<int> nums = {12,3,1,6,1,6,6,6,6,4,3,8,13,13,13,8};

    cout << "Longest subarray of maximum possible bitwise (and) value : = " << longest_subarray(nums);

    return 0;
}