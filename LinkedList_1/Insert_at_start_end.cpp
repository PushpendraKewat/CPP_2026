#include <iostream>

using std::cout;
using std::endl;

// Node class
class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = nullptr;
    }
};

// Linked List class
class LinkedList {
public:
    Node* head;
    Node* tail;
    int size;

    LinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    // Insert at End
    void insertAtTail(int val) {
        Node* temp = new Node(val);

        if (size == 0) {
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }

        size++;
    }

    // Insert at Head
    void insertAtHead(int val) {
        Node* temp = new Node(val);

        if (size == 0) {
            head = tail = temp;
        } else {
            temp->next = head;
            head = temp;
        }

        size++;
    }

    // Display Linked List
    void display() {
        Node* temp = head;

        while (temp != nullptr) {
            cout << temp->val << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList ll;

    cout << "\nInserting at Tail..." << endl;
    ll.insertAtTail(20);
    ll.display();
    ll.insertAtTail(30);
    ll.display();
    ll.insertAtTail(40);

    ll.display();
    cout << "\nSize after inserting at tail = " << ll.size << endl;

    cout << "\nInserting at Head..." << endl;
    ll.insertAtHead(10);
    ll.display();

    ll.insertAtHead(5);
    ll.display();

    cout << "\nSize after inserting at head = " << ll.size << endl;

    return 0;
}