#include<iostream>
#include<vector>
#include<algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int> ans;

        // Case 1
        if (x < arr[0]) {
            for (int i = 0; i < k; i++) {
                ans.push_back(arr[i]);
            }
            return ans;
        }

        // Case 2
        if (x > arr[n - 1]) {
            for (int i = n - k; i < n; i++) {
                ans.push_back(arr[i]);
            }
            return ans;
        }

        int low = 0, high = n - 1;
        int mid = -1;

        // Step 1: Binary Search
        while (low <= high) {
            mid = low + (high - low) / 2;

            if (arr[mid] == x) break;
            else if (arr[mid] < x) low = mid + 1;
            else high = mid - 1;
        }

        // Step 2: Set pointers based on your idea
        int left, right;

        if (arr[mid] == x) {
            left = mid - 1;
            right = mid + 1;
            ans.push_back(arr[mid]); // include x
            k--; // one element already taken
        } else {
            left = high;   // last smaller
            right = low;   // first greater
        }

        // Step 3: Expand (your missing part)
        while (k--) {
            if (left < 0) {
                ans.push_back(arr[right++]);
            }
            else if (right >= n) {
                ans.push_back(arr[left--]);
            }
            else if (abs(arr[left] - x) <= abs(arr[right] - x)) {
                ans.push_back(arr[left--]);
            }
            else {
                ans.push_back(arr[right++]);
            }
        }

        // Step 4: Sort result
        std::sort(ans.begin(), ans.end());
        return ans;
    }
};