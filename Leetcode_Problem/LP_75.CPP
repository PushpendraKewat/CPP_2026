#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;


// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int n = nums.size();
//         int no0 = 0, no1 = 0, no2 = 0;

//         for(int i = 0; i < n; i++){
//             if(nums[i] == 0) no0++;
//             else if(nums[i] == 1) no1++;
//             else no2++;
//         }

//         for(int i = 0; i < n; i++){
//             if(i < no0)
//                 nums[i] = 0;
//             else if(i < no0 + no1)
//                 nums[i] = 1;
//             else
//                 nums[i] = 2;
//         }
//     }
// };


// 3 pointer(approach)  or Dutch national flag

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;

        while(mid <= high){
            if(nums[mid] == 2){
                std::swap(nums[mid], nums[high]);
                high--;
            }
            else if(nums[mid] == 0){
                std::swap(nums[mid], nums[low]);
                low++;
                mid++;
            }
            else{ // nums[mid] == 1
                mid++;
            }
        }
    }
};
