#include<iostream>
#include<vector>
#include<algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::min;
using std::max;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        vector<int> leftMax(n, -1);
        vector<int> rightMax(n, -1);

        // Prefix Maximum (Left Max)
        int pmax = height[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = pmax;
            pmax = max(pmax, height[i]);
        }

        // Suffix Maximum (Right Max)
        int nmax = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = nmax;
            nmax = max(nmax, height[i]);
        }

        // Calculate trapped water
        int water = 0;
        for (int i = 0; i < n; i++) {
            int level = min(leftMax[i], rightMax[i]);
            if (level > height[i]) {
                water += level - height[i];
            }
        }

        return water;
    }
};
