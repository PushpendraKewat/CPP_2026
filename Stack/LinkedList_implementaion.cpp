#include <iostream>

using std::cout;
using std::endl;

class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        next = nullptr;
    }
};

class Stack {
public:
    Node* head;
    int sz;

    Stack() {
        head = nullptr;
        sz = 0;
    }

    void push(int val) {
        Node* temp = new Node(val);
        temp->next = head;
        head = temp;
        sz++;
    }

    void pop() {
        if (head == nullptr) {
            cout << "Stack Underflow\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
        sz--;
    }

    int top() {
        if (head == nullptr) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return head->val;
    }

    int size() {
        return sz;
    }

    bool empty() {
        return head == nullptr;
    }

    void display(){
        Node* temp = head;
        while(temp!=nullptr){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    void displayRev(Node* temp) {
        if (temp == nullptr) return;

        displayRev(temp->next);
        cout << temp->val << " ";
    }
};

int main() {
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Size: " << st.size() << endl;
    cout << "Top: " << st.top() << endl;

    st.display();          // 30 20 10
    st.displayRev(st.head); // 10 20 30
    cout << endl;

    st.pop();

    st.display();          // 20 10
    st.displayRev(st.head); // 10 20
    cout << endl;
}