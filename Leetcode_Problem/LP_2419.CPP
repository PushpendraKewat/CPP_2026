class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int mx = INT_MIN;
        int count = 0;
        int ans = 0;

        for(int i=0;i<n;i++){
            if(nums[i]>mx){
                mx = nums[i];
                count = 1;
                ans = 1;
            }
            else if(nums[i]==mx){
                count++;
                ans = max(ans,count);
            }
            else count = 0;
        }
        return ans;

    }
};