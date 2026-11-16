1524. Number of Sub-arrays With Odd Sum
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        long long even = 0, odd = 0, ans = 0;

        for (int x : arr) {
            if (x % 2 == 0) {
                even++;
            } else {
                swap(even, odd);
                odd++;
            }

            ans = (ans + odd) % MOD;
        }

        return ans;
    }
};



class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int sum = 0;

            for (int j = i; j < n; j++) {
                sum += arr[j];

                if (sum % 2 == 1) {
                    ans++;
                }
            }
        }

        return ans % MOD;
    }
};