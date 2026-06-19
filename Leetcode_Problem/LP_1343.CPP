#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int target = k * threshold;

        int i = 0, j = 0;
        int sum = 0;
        int count = 0;

        while (j < n) {
            sum += arr[j];

            // Window size becomes k
            if (j - i + 1 == k) {
                if (sum >= target) {
                    count++;
                }

                // Slide the window
                sum -= arr[i];
                i++;
            }

            j++;
        }

        return count;
    }
};