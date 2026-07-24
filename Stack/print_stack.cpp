#include <iostream>
#include <stack>

using std::cout;
using std::cin;
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
    while(st.size()>0){ // !st.empty()
        cout<<st.top()<<"  ";
        int x = st.top();
        st.pop();
        temp.push(x);
    }
    cout<<endl;
    // putting elemt back to st 
    while(!temp.empty()){
        cout<<temp.top()<<" ";
        int x = temp.top();
        temp.pop();
        st.push(x);
    }
    cout<<endl;
    while(st.size()>0){ // !st.empty()
        cout<<st.top()<<"  ";
        int x = st.top();
        st.pop();
        temp.push(x);
    }
    return 0;
}