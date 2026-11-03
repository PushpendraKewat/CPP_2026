// 3736. Minimum Moves to Equal Array Elements III
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxele = INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i] > maxele) maxele = nums[i];
        }
        int moves = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=maxele){
                moves += maxele - nums[i];
            }
        }
        return moves;
    }
};