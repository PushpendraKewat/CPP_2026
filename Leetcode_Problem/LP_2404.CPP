#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int ans = -1, maxFreq = 0;

        for(int i = 0; i < n; ){
            if(nums[i] % 2 != 0){
                i++;
                continue;
            }

            int j = i;
            while(j < n && nums[j] == nums[i]) j++;

            int freq = j - i;

            if(freq > maxFreq){
                maxFreq = freq;
                ans = nums[i];
            }

            i = j; // move to next new element
        }

        return ans;
    }
};