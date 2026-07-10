#include <iostream>

using namespace std;

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

    // Insert at Tail
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

    // Insert at Index
    void insertAtIndex(int idx, int val) {

        if (idx < 0 || idx > size) {
            cout << "Invalid Index" << endl;
            return;
        }

        if (idx == 0) {
            insertAtHead(val);
            return;
        }

        if (idx == size) {
            insertAtTail(val);
            return;
        }

        Node* t = new Node(val);
        Node* temp = head;

        for (int i = 0; i < idx - 1; i++) {
            temp = temp->next;
        }

        t->next = temp->next;
        temp->next = t;

        size++;
    }

    // Get element at Index
    int getIndex(int idx) {

        if (idx < 0 || idx >= size) {
            cout << "Invalid Index" << endl;
            return -1;
        }

        if (idx == 0)
            return head->val;

        if (idx == size - 1)
            return tail->val;

        Node* temp = head;

        for (int i = 1; i <= idx; i++) {
            temp = temp->next;
        }

        return temp->val;
    }

    // Delete at Head
    void deleteAtHead() {

        if (size == 0) {
            cout << "Linked List is Empty" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;

        delete temp;
        size--;

        if (size == 0) {
            head = tail = nullptr;
        }
    }

    // Delete at Tail
    void deleteAtTail() {

        if (size == 0) {
            cout << "Linked List is Empty" << endl;
            return;
        }

        if (size == 1) {
            delete head;
            head = tail = nullptr;
            size--;
            return;
        }

        Node* temp = head;

        while (temp->next != tail) {
            temp = temp->next;
        }

        delete tail;
        tail = temp;
        tail->next = nullptr;

        size--;
    }

    // Delete at Index
    void deleteAtIndex(int idx) {

        if (idx < 0 || idx >= size) {
            cout << "Invalid Index" << endl;
            return;
        }

        if (idx == 0) {
            deleteAtHead();
            return;
        }

        if (idx == size - 1) {
            deleteAtTail();
            return;
        }

        Node* temp = head;

        for (int i = 0; i < idx - 1; i++) {
            temp = temp->next;
        }

        Node* t = temp->next;

        temp->next = t->next;

        delete t;

        size--;
    }

    // Display
    void display() {

        if (size == 0) {
            cout << "Linked List is Empty" << endl;
            return;
        }

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

    cout << "Insert at Tail:" << endl;
    ll.insertAtTail(20);
    ll.display();
    ll.insertAtTail(30);
    ll.display();
    ll.insertAtTail(40);
    ll.display();
    cout << "\nSize after all tail insertion = " << ll.size << endl;

    cout << "\nInsert at Head:" << endl;
    ll.insertAtHead(10);
    ll.display();
    ll.insertAtHead(5);
    ll.display();
    cout << "\nSize after all head insertion = " << ll.size << endl;

    cout << "\nInsert 80 at index 4:" << endl;
    cout<<"Before insertion at index : ";
    ll.display();
    ll.insertAtIndex(4, 80);
    cout<<endl;
    cout<<"after insertion at index : ";
    ll.display();
    
    cout << "\nSize = " << ll.size << endl;

    cout << "\nElement at index 5 = " << ll.getIndex(5) << endl;

    cout << "\nDelete Head:" << endl;
    ll.deleteAtHead();
    ll.display();

    cout << "\nDelete Tail:" << endl;
    ll.deleteAtTail();
    ll.display();

    cout << "\nDelete Index 2:" << endl;
    ll.deleteAtIndex(2);
    ll.display();

    cout << "\nFinal Size = " << ll.size << endl;

    return 0;
}