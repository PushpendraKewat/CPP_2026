class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int,vector<int>,greater<int>> mnHeap;
        for(int i=0;i<n;i++){
           mnHeap.push(nums[i]);
           if(mnHeap.size() > k){
            mnHeap.pop();
           } 
        }
        return mnHeap.top();
    }
};