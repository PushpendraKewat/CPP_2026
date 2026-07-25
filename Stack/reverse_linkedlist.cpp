#include <iostream>
#include <stack>

using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int x) {
        val = x;
        next = nullptr;
    }
};

int main() {
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    cout << "Original Stack:\n";
    stack<int> temp = st;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }

    // Create linked list
    Node* head = nullptr;
    Node* tail = nullptr;

    while (!st.empty()) {
        Node* newNode = new Node(st.top());
        st.pop();

        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Push linked list elements back into stack
    Node* curr = head;
    while (curr != nullptr) {
        st.push(curr->val);
        curr = curr->next;
    }

    cout << "\n\nReversed Original Stack:\n";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}