#include <iostream>
#include <vector>
#include <queue>

using std::cout;
using std::endl;
using std::vector;
using std::queue;

vector<int> firstNegativeWindow(vector<int>& v, int k) {
    int n = v.size();
    vector<int> ans;
    queue<int> q;

    // Store indices of negative elements
    for (int i = 0; i < n; i++) {
        if (v[i] < 0)
            q.push(i);
    }

    // Process each window
    for (int i = 0; i < n - k+1; i++) {

        // Remove indices outside the current window
        while (!q.empty() && q.front() < i) q.pop();

        // Check if first negative lies inside current window
        if (!q.empty() && q.front() <= i + k - 1)
            ans.push_back(v[q.front()]);
        else
            ans.push_back(0);
    }

    return ans;
}

int main() {
    vector<int> v = {0, -1, -2, 3, 4, -5, 6, 4, 7, -8};
    int k = 3;

    vector<int> ans = firstNegativeWindow(v, k);

    for (int x : ans)
        cout << x << " ";
}