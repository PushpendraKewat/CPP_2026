#include <iostream>
#include <stack>

using namespace std;

// Display stack using recursion
void displayRecursion(stack<int>& st) {
    if (st.empty())
        return;

    int x = st.top();
    st.pop();

    cout << x << " ";

    displayRecursion(st);

    st.push(x);   // Restore the stack
}

// Push element at bottom using recursion
void pushAtBottomRec(stack<int>& st, int value) {
    if (st.empty()) {
        st.push(value);
        return;
    }

    int x = st.top();
    st.pop();

    pushAtBottomRec(st, value);

    st.push(x);
}

int main() {
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    cout << "Original Stack: ";
    displayRecursion(st);

    pushAtBottomRec(st, 90);

    cout << "\nAfter Push at Bottom: ";
    displayRecursion(st);

    return 0;
}