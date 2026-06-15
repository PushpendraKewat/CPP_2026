#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());

        vector<int> suffix(n);
        suffix[n - 1] = satisfaction[n - 1];

        for(int i = n - 2; i >= 0; i--) {
            suffix[i] = satisfaction[i] + suffix[i + 1];
        }

        int idx = -1;

        for(int i = 0; i < n; i++) {
            if(suffix[i] > 0) {
                idx = i;
                break;
            }
        }

        if(idx == -1) return 0;

        int ans = 0;
        int time = 1;

        for(int i = idx; i < n; i++) {
            ans += satisfaction[i] * time;
            time++;
        }

        return ans;
    }
};