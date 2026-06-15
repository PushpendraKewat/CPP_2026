#include <iostream>
#include <vector>
#include<string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();

        vector<int> prefix(n + 1);
        prefix[0] = 0;

        // prefix[i] = number of N's before hour i
        for(int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i];
            if(customers[i] == 'N') {
                prefix[i + 1]++;
            }
        }

        vector<int> suffix(n + 1);
        suffix[n] = 0;
        
        // suffix[i] = number of Y's from i to n-1
        for(int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1];
            if(customers[i] == 'Y') {
                suffix[i]++;
            }
        }

        int ans = 0;
        int minPenalty = INT_MAX;

        for(int i = 0; i <= n; i++) {
            int penalty = prefix[i] + suffix[i];

            if(penalty < minPenalty) {
                minPenalty = penalty;
                ans = i;
            }
        }

        return ans;
    }
};