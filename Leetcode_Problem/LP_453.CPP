// 453. Minimum Moves to Equal Array Elements
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        int minele = INT_MAX;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            if(nums[i]<minele){
                minele = nums[i];
            }
        }
        int moves = sum - n*minele;
        return moves;
    }
};