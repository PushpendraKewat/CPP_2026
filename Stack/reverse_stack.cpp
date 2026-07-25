#include <iostream>
#include <stack>

using std::cout;
using std::endl;
using std::stack;

int main() {
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    stack<int> temp;
    cout << "Original stack :" << endl;
    // st->temp
    while (!st.empty()) {
        cout << st.top() << " ";
        temp.push(st.top());
        st.pop();
    }

    // temp -> temp2
    stack<int> temp2;
    while (!temp.empty()) {
        temp2.push(temp.top());
        temp.pop();
    }

    // temp2 -> st
    while (!temp2.empty()) {
        st.push(temp2.top());
        temp2.pop();
    }

    cout << "\n\nReversed original stack :" << endl;
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}