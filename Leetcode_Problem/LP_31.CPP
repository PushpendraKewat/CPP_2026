#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:

    void mySwap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }

    void myReverse(int start, vector<int>& nums){
        int i = start;
        int j = nums.size() - 1;

        while(i < j){
            mySwap(nums[i], nums[j]);
            i++;
            j--;
        }
    }

    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        // step 1 find pivot
        int pivotidx = -1;
        for(int i = n - 2; i >= 0; i--){
            if(nums[i] < nums[i + 1]){
                pivotidx = i;
                break;
            }
        }

        // step 2 If no pivot, reverse entire array
        if(pivotidx == -1){
            myReverse(0, nums);
            return;
        }

        // stap 3  Find successor and swap
        for(int j = n - 1; j > pivotidx; j--){
            if(nums[j] > nums[pivotidx]){
                mySwap(nums[j], nums[pivotidx]);
                break;
            }
        }

        // step 4  Reverse suffix
        myReverse(pivotidx + 1, nums);
    }
};
