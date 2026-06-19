#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxlen = 0;
        int i = 0, j = 0, flips = 0;

        while (j < n) {
            if (nums[j] == 1) {
                j++;
            } 
            else {
                if (flips < k) {
                    flips++;
                    j++;
                } 
                else {
                    maxlen = std::max(maxlen, j - i);

                    while (i < n && nums[i] != 0) {
                        i++;
                    }

                    i++;
                    flips--;
                }
            }
        }

        maxlen = std::max(maxlen, j - i);

        return maxlen;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;

    cout << "Answer: " << obj.longestOnes(nums, k) << endl;

    return 0;
}