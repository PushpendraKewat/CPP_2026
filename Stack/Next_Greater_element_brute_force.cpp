#include <iostream>
#include <vector>

using std::cout; 
using std::endl; 
using std::vector;

vector<int> nextGreaterElement(vector<int>& v) {
    int n = v.size();
    vector<int> ans(n, -1);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[j] > v[i]) {
                ans[i] = v[j];
                break;
            }
        }
    }

    return ans;
}

int main() {
    vector<int> v = {3,1,2,5,4,6,2,3};

    vector<int> ans = nextGreaterElement(v);

    for (int x : ans)
        cout << x << " ";
}