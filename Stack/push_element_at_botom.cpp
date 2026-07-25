#include <iostream>
#include <stack>
#include <vector>

using std::cout;
using std::endl;
using std::stack;
using std::vector;

int main() {
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    stack<int> helper;
    while(!st.empty()){
        helper.push(st.top());
        st.pop();
    }
    st.push(70);
    while(!helper.empty()){
        st.push(helper.top());
        helper.pop();
    }
    // print stack
    cout<<"Push at bottom stack :";
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}