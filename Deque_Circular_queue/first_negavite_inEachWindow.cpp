#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

vector<int> firstNegativeWindow(vector<int>& v, int k) {
    int n = v.size();
    vector<int> ans;

    // Traverse each window
    for (int i = 0; i <= n - k; i++) {
        bool found = false;

        // Check all elements in the current window
        for (int j = i; j < i + k; j++) {
            if (v[j] < 0) {
                ans.push_back(v[j]);
                found = true;
                break;
            }
        }

        // No negative element in this window
        if (!found) {
            ans.push_back(0);      // or -1 depending on the problem
        }
    }

    return ans;
}

int main() {
    vector<int> v = {0, -1, -2, 3, 4, -5, 6, 4, 7, -8};
    int k = 3;

    vector<int> ans = firstNegativeWindow(v, k);

    for (int x : ans)
        cout << x << " ";

    return 0;
}