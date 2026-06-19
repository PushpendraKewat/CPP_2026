#include <iostream>
#include <vector>
#include <climits>

using namespace std;

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
            else { // nums[j] == 0
                if (flips < k) {
                    flips++;
                    j++;
                } 
                else { // flips == k
                    maxlen = max(maxlen, j - i);

                    while (i < n && nums[i] != 0) {
                        i++;
                    }

                    i++;      // remove the leftmost zero
                    flips--;  // one flipped zero left the window
                }
            }
        }

        maxlen = max(maxlen, j - i);

        return maxlen;
    }
};