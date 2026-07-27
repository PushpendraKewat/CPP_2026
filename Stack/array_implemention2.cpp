#include <iostream>

using std::cout;
using std::endl;

class Stack {   // user-defined stack
public:
    int arr[5];
    int idx;

    // constructor
    Stack() {
        idx = -1;
    }

    void push(int val) {
        if (idx == 4) {
            cout << "Stack Overflow\n";
            return;
        }
        idx++;
        arr[idx] = val;
    }

    void pop() {
        if (idx == -1) {
            cout << "Stack Underflow\n";
            return;
        }
        idx--;
    }

    int top() {
        if (idx == -1) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return arr[idx];
    }

    int size() {
        return idx + 1;
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