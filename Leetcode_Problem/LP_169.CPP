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
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int candidate = 0;
        int count = 0;

        for(int i = 0; i < n; i++){
            if(count == 0){
                candidate = nums[i];
            }

            if(nums[i] == candidate){
                count++;
            } else {
                count--;
            }
        }

        return candidate;
    }
};


// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int n = nums.size();
//         return nums[n/2];
//     }
// };