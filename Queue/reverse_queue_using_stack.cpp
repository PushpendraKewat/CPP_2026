#include<iostream>
#include<queue>
#include<stack>

using std::cout;
using std::endl;
using std::queue;
using std::stack;

void display(queue<int>& q){
    int n = q.size();
    for(int i=0;i<n;i++){
        int x = q.front();
        cout << x << " ";
        q.pop();
        q.push(x);
    }
    cout << endl;
}

void reverseDisplay(queue<int>& q){
    stack<int> st;

    // empty() queue and push into stack
    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }
    // now empty() stack and push into queue
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }

    // now queue is reverse 
    int n = q.size();
    for(int i=0;i<n;i++){
        int x = q.front();
        cout << x << " ";
        q.pop();
        q.push(x);
    }
    cout << endl;
}

int main(){
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    display(q);
    reverseDisplay(q);

    return 0;
}