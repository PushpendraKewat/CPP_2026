#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::vector;

int longestCommonSubstring(string s1, string s2) {
    int m = s1.size();
    int n = s2.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    int ans = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = std::max(ans, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }

    return ans;
}

int main() {
    string s1 = "abcdgh";
    string s2 = "acdghr";

    cout << "Length of Longest Common Substring: "
         << longestCommonSubstring(s1, s2) << endl;

    return 0;
}