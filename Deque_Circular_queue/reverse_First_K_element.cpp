#include <iostream>
#include <queue>
#include <stack>

using std::cout;
using std::endl;
using std::queue;
using std::stack;

void display(queue<int>& q){
    int n = q.size();
    for(int i = 0;i<n;i++){
        int  x = q.front();
        cout<<x<<" ";
        q.pop();
        q.push(x);
    }
    cout<<endl;
}

queue<int> reverseFirstK(queue<int>& q, int k) {
    if (k <= 0 || k > q.size())
        return q;

    stack<int> st;
    int n = q.size();

    // Store first k elements in stack
    for (int i = 0; i < k; i++) {
        st.push(q.front());
        q.pop();
    }

    // Put them back in reversed order
    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }

    // Move remaining elements to the back
    for (int i = 0; i < n - k; i++) {
        q.push(q.front());
        q.pop();
    }

    return q;
}

int main() {
    queue<int> q;
    int k = 2;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    display(q);

    reverseFirstK(q, k);

    display(q);

    return 0;
}