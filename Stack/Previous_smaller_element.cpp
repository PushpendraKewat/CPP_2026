#include <iostream>
#include <vector>
#include <stack>

using std::cout;
using std::endl;
using std::vector;
using std::stack;

// Previous Smaller Element (Value)
vector<int> previousSmallerElement(vector<int>& v) {
    int n = v.size();
    vector<int> pse(n);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() >= v[i]) {
            st.pop();
        }

        if (st.empty())
            pse[i] = -1;
        else
            pse[i] = st.top();

        st.push(v[i]);
    }

    return pse;
}

int main() {
    vector<int> v = {2,1,5,6,2,3};

    vector<int> pse = previousSmallerElement(v);

    cout << "Array: ";
    for (int x : v)
        cout << x << " ";
    cout << endl;

    cout << "Previous Smaller Element: ";
    for (int x : pse)
        cout << x << " ";
    cout << endl;

    return 0;
}