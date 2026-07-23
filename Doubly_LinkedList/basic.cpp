#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode* prev;

    ListNode(int val) {
        this->val = val;
        next = nullptr;
        prev = nullptr;
    }
};

// Display from head to tail
void displayForward(ListNode* head) {
    ListNode* temp = head;

    while (temp != nullptr) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

// Display from tail to head
void displayReverse(ListNode* tail) {
    ListNode* temp = tail;

    while (temp != nullptr) {
        cout << temp->val << " <- ";
        temp = temp->prev;
    }

    cout << "NULL" << endl;
}

int main() {
    // Create nodes
    ListNode* a = new ListNode(10);
    ListNode* b = new ListNode(20);
    ListNode* c = new ListNode(30);
    ListNode* d = new ListNode(40);
    ListNode* e = new ListNode(50);

    // Connect next pointers
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    // Connect prev pointers
    b->prev = a;
    c->prev = b;
    d->prev = c;
    e->prev = d;

    // Head and Tail
    ListNode* head = a;
    ListNode* tail = e;

    cout << "Forward Traversal:" << endl;
    displayForward(head);

    cout << "Reverse Traversal:" << endl;
    displayReverse(tail);

    // Free memory
    delete a;
    delete b;
    delete c;
    delete d;
    delete e;

    return 0;
}