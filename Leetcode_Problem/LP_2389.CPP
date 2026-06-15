
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        // Prefix sum in-place
        for(int i = 1; i < n; i++) {
            nums[i] += nums[i - 1];
        }

        vector<int> ans;

        for(int i = 0; i < queries.size(); i++) {
            int len = 0;

            for(int j = 0; j < n; j++) {
                if(queries[i] >= nums[j]) {
                    len++;
                }
            }

            ans.push_back(len);
        }

        return ans;
    }
};