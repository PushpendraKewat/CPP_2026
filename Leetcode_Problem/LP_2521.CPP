class Solution {
public:
    void fillseive(vector<int>& seive) {
        int n = seive.size() - 1;

        for (int i = 2; i * i <= n; i++) {
            if (seive[i]) {
                for (int j = i * i; j <= n; j += i) {
                    seive[j] = 0;
                }
            }
        }
    }

    int distinctPrimeFactors(vector<int>& nums) {

        int mx = *max_element(nums.begin(), nums.end());

        vector<int> seive(mx + 1, 1);
        seive[0] = seive[1] = 0;

        fillseive(seive);

        // vis[i] = 1 means prime factor i has appeared
        vector<int> vis(mx + 1, 0);

        for (int num : nums) {

            int temp = num;

            for (int p = 2; p * p <= temp; p++) {

                if (seive[p] && temp % p == 0) {

                    vis[p] = 1;

                    while (temp % p == 0) {
                        temp /= p;
                    }
                }
            }

            if (temp > 1) {
                vis[temp] = 1;
            }
        }

        int count = 0;

        for (int i = 2; i <= mx; i++) {
            if (vis[i]) {
                count++;
            }
        }

        return count;
    }
};