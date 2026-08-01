#include <iostream>

using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        next = nullptr;
    }
};

class Queue {
private:
    Node* front;
    Node* back;
    int sz;

public:
    Queue() {
        front = back = nullptr;
        sz = 0;
    }

    void push(int val) {
        Node* temp = new Node(val);

        if (back == nullptr) {
            front = back = temp;
        } else {
            back->next = temp;
            back = temp;
        }

        sz++;
    }

    void pop() {
        if (empty()) {
            cout << "Queue is empty\n";
            return;
        }

        Node* temp = front;
        front = front->next;
        delete temp;
        sz--;

        if (front == nullptr)
            back = nullptr;
    }

    int Front() {
        if (empty()) return -1;
        return front->val;
    }

    int Back() {
        if (empty()) return -1;
        return back->val;
    }

    int size() {
        return sz;
    }

    bool empty() {
        return sz == 0;
    }

    void display() {
        Node* temp = front;

        while (temp != nullptr) {
            cout << temp->val << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    q.display();

    q.pop();
    q.pop();

    q.display();

    cout << "Front: " << q.Front() << endl;
    cout << "Back : " << q.Back() << endl;
    cout << "Size : " << q.size() << endl;

    return 0;
}