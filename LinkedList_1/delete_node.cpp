#include<iostream>

using std::cout;
using std::endl;

class Node { // user defined datatype
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = nullptr;
    }
};

Node* deleteNode(Node* head, Node* target) {

    if (head == target) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* temp = head;

    while (temp->next != target) {
        temp = temp->next;
    }

    temp->next = target->next;
    delete target;

    return head;
}
void display(Node* head) {
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);
    Node* e = new Node(50);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    Node* head = a;

    display(head);

    head = deleteNode(head,b); //delete with help of head node
    display(head);

    return 0;
}