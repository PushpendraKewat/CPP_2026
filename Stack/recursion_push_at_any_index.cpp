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

// Push element at any index
void pushAtAnyIdxRec(stack<int>& st, int idx, int value) {
    if (idx == 0) {
        st.push(value);
        return;
    }

    if (st.empty()) {
        cout << "Invalid Index\n";
        return;
    }

    int x = st.top();
    st.pop();

    pushAtAnyIdxRec(st, idx - 1, value);

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

    pushAtAnyIdxRec(st,2,90);

    cout << "\nAfter Push 90 at idx 2: ";
    displayRecursion(st);


    return 0;
}