#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefix(n);
        vector<int> suffix(n);

        prefix[0] = 1;
        suffix[n - 1] = 1;

        int product = nums[0];

        for(int i = 1; i < n; i++) {
            prefix[i] = product;
            product *= nums[i];
        }

        product = 1;

        for(int i = n - 1; i >= 0; i--) {
            suffix[i] = product;
            product *= nums[i];
        }

        for(int i = 0; i < n; i++) {
            prefix[i] = prefix[i] * suffix[i];
        }

        return prefix;
    }
};