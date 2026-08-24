#include<iostream>
#include<vector>
#include<queue>

using std::cout;
using std::endl;
using std::vector;
using std::priority_queue;

int kthSmallest(vector<int>& v, int k) {
    priority_queue<int> mxHeap;
    for (int i = 0; i < v.size(); i++) {
        mxHeap.push(v[i]);
        if (mxHeap.size() > k) {
            mxHeap.pop();
        }
    }
    return mxHeap.top();
}

int main() {
    vector<int> v = {10, 20, -4, 6, 18, 2, 105, 118};
    int k = 3;
    cout << kthSmallest(v, k) << endl;

    return 0;
}