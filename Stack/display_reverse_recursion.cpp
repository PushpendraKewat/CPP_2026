#include <iostream>
#include <stack>

using std::cout;
using std::endl;
using std::stack;

void displayReverseRecursion(stack<int>& st) {
    if (st.empty()) return;

    int x = st.top();
    st.pop();

    displayReverseRecursion(st);

    cout << x << " ";   // Print while backtracking
    st.push(x);         // Restore the stack
}



int main() {
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    displayReverseRecursion(st);
    return 0;
}