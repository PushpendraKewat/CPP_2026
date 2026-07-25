#include <iostream>
#include <stack>

using std::cout;
using std::endl;
using std::stack;

void displayRecursion(stack<int>& st) {
    if (st.empty()) return;

    cout << st.top() << " ";
    st.pop();

    displayRecursion(st);
}


int main() {
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    displayRecursion(st);
    return 0;
}