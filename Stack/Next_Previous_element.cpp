#include <iostream>
#include <vector>
#include <stack>

using std::cout;
using std::endl;
using std::vector;
using std::stack;

// Next Smaller Element (Value)
vector<int> nextSmallerElement(vector<int>& v) {
    int n = v.size();
    vector<int> nse(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() >= v[i]) {
            st.pop();
        }

        if (st.empty())
            nse[i] = -1;
        else
            nse[i] = st.top();

        st.push(v[i]);
    }

    return nse;
}

int main() {
    vector<int> v = {2,1,5,6,2,3};

    vector<int> nse = nextSmallerElement(v);

    cout << "Array: ";
    for (int x : v)
        cout << x << " ";
    cout << endl;

    cout << "Next Smaller Element: ";
    for (int x : nse)
        cout << x << " ";
    cout << endl;

    return 0;
}