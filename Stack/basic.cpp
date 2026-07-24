#include <iostream>
#include <stack>

using std::cout;
using std::cin;
using std::endl;
using std::stack;

int main() {
    stack<int> st;

    st.push(10); // Push 10
    st.push(20); // Push 20
    st.push(30); // Push 30

    cout << st.size() << endl; // 3

    st.pop(); // Remove 30

    cout << st.top() << endl;  // 20

    cout << st.size() << endl; // 2

    return 0;
}