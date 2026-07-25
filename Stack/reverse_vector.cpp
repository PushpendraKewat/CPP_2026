#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    cout << "Original stack:\n";
    stack<int> temp = st;   // Copy only for printing
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }

    // Store elements in vector
    vector<int> v;
    while (!st.empty()) {
        v.push_back(st.top());
        st.pop();
    }

    // Push back into original stack
    for (int i = 0; i < v.size(); i++) {
        st.push(v[i]);
    }

    cout << "\n\nReversed original stack:\n";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}