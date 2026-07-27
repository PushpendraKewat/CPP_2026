#include <iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;

class Stack {   // user-defined stack
public:
    vector<int> v; // no overflow condition
  
    // constructor
    Stack() {
        
    }

    void push(int val) {
        v.push_back(val);
    }

    void pop() {
        if(v.size()==0){
            cout<<"stack underflow";
        }
        v.pop_back();
    }

    int top() {
        if(v.size()==0){
            cout<<"stack is empty";
            return -1;
        }
        return v[v.size()-1];
    }

    int size() {
       return v.size();
    }
};

int main() {
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << st.size() << endl;
    cout << st.top() << endl;
    st.push(40);
    st.push(50);
    st.push(60);
    cout<<st.top()<<endl;

}