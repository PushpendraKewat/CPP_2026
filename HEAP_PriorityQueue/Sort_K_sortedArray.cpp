#include <iostream>
#include <queue>
#include <vector>

using std::cout;
using std::endl;
using std::priority_queue;
using std::vector;
using std::greater;

vector<int> result(vector<int>& v, int k) {
    priority_queue<int, vector<int>, greater<int>> mnHeap;
    vector<int> ans;

    for (int i = 0; i < v.size(); i++) {
        mnHeap.push(v[i]);

        if (mnHeap.size() > k) {
            ans.push_back(mnHeap.top());
            mnHeap.pop();
        }
    }

    while (!mnHeap.empty()) {
        ans.push_back(mnHeap.top());
        mnHeap.pop();
    }

    return ans;
}

int main() {
    vector<int> v = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;

    vector<int> ans = result(v, k);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}