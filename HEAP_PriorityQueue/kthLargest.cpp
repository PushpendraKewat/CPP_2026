#include<iostream>
#include<vector>
#include<queue>

using std::cout;
using std::endl;
using std::vector;
using std::priority_queue;
using std::greater;

int kthLargest(vector<int>& v, int k) {
    priority_queue<int, vector<int>, greater<int>> mnHeap;

    for (int i = 0; i < v.size(); i++) {
        mnHeap.push(v[i]);

        if (mnHeap.size() > k) {
            mnHeap.pop();
        }
    }

    return mnHeap.top();
}

int main() {
    vector<int> v = {10, 20, -4, 6, 18, 2, 105, 118};
    int k = 3;

    cout << kthLargest(v, k) << endl;

    return 0;
}