#include<iostream>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

class Solution {
public:
    void rotatePart(int i, int j, vector<int>& v){
        while(i < j){
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
            i++;
            j--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // if k>n

        rotatePart(0, n-k-1, nums);
        rotatePart(n-k, n-1, nums);
        rotatePart(0, n-1, nums);
    }
};
