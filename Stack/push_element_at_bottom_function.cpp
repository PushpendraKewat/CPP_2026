#include <iostream>
#include <stack>

using std::cout;
using std::endl;
using std::stack;


// Function to print stack
void printStack(stack<int> st) {   // Pass by value to preserve original stack
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

// Function to push an element at the bottom of the stack
void pushAtBottom(stack<int> &st, int x) {
    stack<int> helper;

    // Move all elements to helper
    while (!st.empty()) {
        helper.push(st.top());
        st.pop();
    }

    // Push new element
    st.push(x);

    // Move elements back
    while (!helper.empty()) {
        st.push(helper.top());
        helper.pop();
    }
}

int main() {
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    cout << "Original Stack: ";
    printStack(st);

    pushAtBottom(st, 70);

    cout << "After Push at Bottom: ";
    printStack(st);

    return 0;
}