#include<iostream>

using std::cout;
using std::endl;

class Node{ // User defined data type
    public:
    int val;
    Node* next;

    Node(int val){
        this->val = val;
        this->next = nullptr;
    }
};

class LinkedList{ // user defined data strucutre
    public:
    Node* head;
    Node* tail;
    int size;
    LinkedList(){
        size = 0;
        this->head = nullptr;
        this->tail = nullptr;
    }
    void insertAtEnd(int val){

        Node* temp = new Node(val);   // Create new node
        if(size==0){
            head = tail = temp;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
        size++;
    }
    void display(){
        Node* temp = head;
        while(temp!=nullptr){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }   
};



int main(){
    LinkedList ll;
    ll.insertAtEnd(10); // 10->nulptr
    ll.display();
    cout<<ll.size<<endl;
    ll.insertAtEnd(20); // 10->20->nullptr
    ll.display();
    cout<<ll.size<<endl;
    ll.insertAtEnd(30);
    ll.display();

    return 0;
}