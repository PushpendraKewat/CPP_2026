#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();

    int sum = 0;
    int minlen = INT_MAX;

    int i = 0;
    int j = 0;

    while (j < n) {
        sum += nums[j];

        while (sum >= target) {
            minlen = min(minlen, j - i + 1);
            sum -= nums[i];
            i++;
        }

        j++;
    }

    return (minlen == INT_MAX) ? 0 : minlen;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 6, 3, 4, 3};
    int target = 10;

    cout << "Minimum Length = "
         << minSubArrayLen(target, nums) << endl;

    return 0;
}