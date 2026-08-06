#include<iostream>
#include<stack>
#include<queue>

using std::cout;
using std::endl;
using std::stack;
using std::queue;

void Reorder_Queue(queue<int>& q){
    int n = q.size();
    stack<int> st;
    // queue to stack n/2 with 1st half
    for(int i=0;i<n/2;i++){
        st.push(q.front());
        q.pop();
    }
    // stack to queue
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    // queue to stack n/2 with 2nd half(techinally 1st half)
    for(int i=0;i<n/2;i++){
        st.push(q.front());
        q.pop();
    }
    // one by one stack se queue aur queue to queue
    while(!st.empty()){
        q.push(st.top());
        st.pop();
        q.push(q.front());
        q.pop();
    }
    // reverse the queue with help of stack
    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }
    // now again stack to queue
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }

}

void display(queue<int>& q){
    int n = q.size();
    for(int i=0;i<n;i++){
        int x = q.front();
        cout<<x<<" ";
        q.push(q.front());
        q.pop();
    }
    cout<<endl;
}

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);

    display(q);

    // 1 5 2 6 3 7 4 8
    Reorder_Queue(q);

    display(q);
    return 0;
}