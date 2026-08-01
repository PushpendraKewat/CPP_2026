#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* prev;

    Node(int val) {
        this->val = val;
        next = prev = nullptr;
    }
};

class Deque {
private:
    Node* front;
    Node* rear;
    int sz;

public:
    Deque() {
        front = rear = nullptr;
        sz = 0;
    }

    // Insert at Front
    void pushFront(int val) {
        Node* temp = new Node(val);

        if (front == nullptr) {
            front = rear = temp;
        } else {
            temp->next = front;
            front->prev = temp;
            front = temp;
        }
        sz++;
    }

    // Insert at Rear
    void pushBack(int val) {
        Node* temp = new Node(val);

        if (rear == nullptr) {
            front = rear = temp;
        } else {
            rear->next = temp;
            temp->prev = rear;
            rear = temp;
        }
        sz++;
    }

    // Delete from Front
    void popFront() {
        if (empty()) {
            cout << "Deque is empty\n";
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front != nullptr)
            front->prev = nullptr;
        else
            rear = nullptr;

        delete temp;
        sz--;
    }

    // Delete from Rear
    void popBack() {
        if (empty()) {
            cout << "Deque is empty\n";
            return;
        }

        Node* temp = rear;
        rear = rear->prev;

        if (rear != nullptr)
            rear->next = nullptr;
        else
            front = nullptr;

        delete temp;
        sz--;
    }

    int Front() {
        if (empty()) return -1;
        return front->val;
    }

    int Back() {
        if (empty()) return -1;
        return rear->val;
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
    Deque dq;

    dq.pushBack(20);
    dq.pushBack(30);

    dq.pushFront(10);
    dq.pushFront(5);

    dq.display();

    dq.popFront();
    dq.display();

    dq.popBack();
    dq.display();

    cout << "Front: " << dq.Front() << endl;
    cout << "Back : " << dq.Back() << endl;
    cout << "Size : " << dq.size() << endl;

    return 0;
}