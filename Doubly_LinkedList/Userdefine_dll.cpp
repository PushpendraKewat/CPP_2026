#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int val;
    Node* next;
    Node* prev;

    Node(int val) {
        this->val = val;
        next = nullptr;
        prev = nullptr;
    }
};

// Doubly Linked List class
class DoublyLinkedList {
public:
    Node* head;
    Node* tail;
    int size;

    DoublyLinkedList() {
        head = tail = nullptr;
        size = 0;
    }

    // Insert at Head
    void insertAtHead(int val) {
        Node* temp = new Node(val);

        if (size == 0) {
            head = tail = temp;
        } else {
            temp->next = head;
            head->prev = temp; // extra
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
            temp->prev = tail; // extra
            tail = temp;
        }
        size++;
    }

    // Insert at Index
    void insertAtIndex(int idx, int val) {
        if (idx < 0 || idx > size) {
            cout << "Invalid Index\n";
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

        Node* curr = head;

        for (int i = 0; i < idx - 1; i++)
            curr = curr->next;

        Node* temp = new Node(val);

        temp->next = curr->next;
        temp->prev = curr;

        curr->next->prev = temp; // extra
        curr->next = temp;       // extra

        size++;
    }

    // Get element at Index
    int getIndex(int idx) {
        if (idx < 0 || idx >= size) {
            cout << "Invalid Index\n";
            return -1;
        }

        Node* temp = head;

        for (int i = 0; i < idx; i++)
            temp = temp->next;

        return temp->val;
    }

    // Delete Head
    void deleteAtHead() {
        if (size == 0) {
            cout << "List is Empty\n";
            return;
        }

        if (size == 1) {
            delete head;
            head = tail = nullptr;
            size--;
            return;
        }

        Node* temp = head;

        head = head->next;
        head->prev = nullptr;

        delete temp;
        size--;
    }

    // Delete Tail
    void deleteAtTail() {
        if (size == 0) {
            cout << "List is Empty\n";
            return;
        }

        if (size == 1) {
            delete head;
            head = tail = nullptr;
            size--;
            return;
        }

        Node* temp = tail;

        tail = tail->prev;
        tail->next = nullptr;

        delete temp;
        size--;
    }

    // Delete at Index
    void deleteAtIndex(int idx) {
        if (idx < 0 || idx >= size) {
            cout << "Invalid Index\n";
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

        Node* curr = head;

        for (int i = 0; i < idx; i++)
            curr = curr->next;

        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;

        delete curr;
        size--;
    }

    // Display Forward
    void displayForward() {
        Node* temp = head;

        while (temp != nullptr) {
            cout << temp->val << " <-> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }

    // Display Reverse
    void displayReverse() {
        Node* temp = tail;

        while (temp != nullptr) {
            cout << temp->val << " <-> ";
            temp = temp->prev;
        }

        cout << "NULL\n";
    }
};

int main() {

    DoublyLinkedList dll;

    dll.insertAtTail(20);
    dll.insertAtTail(30);
    dll.insertAtTail(40);

    dll.insertAtHead(10);
    dll.insertAtHead(5);

    cout << "Forward Traversal:\n";
    dll.displayForward();

    cout << "Reverse Traversal:\n";
    dll.displayReverse();

    dll.insertAtIndex(4, 80);

    cout << "\nAfter inserting 80 at index 4:\n";
    dll.displayForward();

    cout << "\nElement at index 5 = " << dll.getIndex(5) << endl;

    dll.deleteAtHead();
    dll.deleteAtTail();
    dll.deleteAtIndex(2);

    cout << "\nAfter Deletions:\n";
    dll.displayForward();

    cout << "Reverse:\n";
    dll.displayReverse();

    cout << "\nSize = " << dll.size << endl;

    return 0;
}