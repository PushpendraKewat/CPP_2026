#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

// Method 1: Using extra array
vector<int> prefixSum1(vector<int>& nums) {
    int n = nums.size();

    vector<int> ans(n);
    ans[0] = nums[0];

    for (int i = 1; i < n; i++) {
        ans[i] = nums[i] + ans[i - 1];
    }

    return ans;
}

// Method 2: In-place prefix sum
void prefixSum2(vector<int>& nums) {
    int n = nums.size();

    for (int i = 1; i < n; i++) {
        nums[i] = nums[i] + nums[i - 1];
    }
}

int main() {
    vector<int> nums = {1, 2, 3, 4};

    // Method 1
    vector<int> res1 = prefixSum1(nums);

    cout << "Method 1 (Extra Array): ";
    for (int x : res1) {
        cout << x << " ";
    }
    cout << endl;

    // Method 2
    prefixSum2(nums);

    cout << "Method 2 (In-place): ";
    for (int x : nums) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}