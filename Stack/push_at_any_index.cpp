#include <iostream>
#include <stack>

using std::cout;
using std::endl;
using std::stack;

void printStack(stack<int> st) {   // Pass by value to preserve original stack
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

void pushAtAnyIdx(stack<int>& st, int idx, int value) {
    if (idx < 0 || idx > st.size()) {
        cout << "Invalid Index\n";
        return;
    }

    stack<int> helper;

    while (st.size() > idx) {
        helper.push(st.top());
        st.pop();
    }

    st.push(value);

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

    pushAtAnyIdx(st,2,90);
    cout<<endl<<"push element at 2 idx with 90 :"<<endl;
    printStack(st);

    return 0;
}