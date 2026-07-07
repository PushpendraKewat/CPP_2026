#include<iostream>

using std::cout;
using std::endl;

class Node{
public:
    int val;
    Node* next;

    Node(int val){
        this->val = val;
        this->next = nullptr;
    }
};

void display(Node* head){

    Node* temp = head;
    while(temp!=nullptr){
       cout<<temp->val<<" ";
       temp = temp->next; 
    }
    cout<<endl;
}

int size(Node* head){

    Node* temp = head;
    int n = 0;
    while(temp!=nullptr){
       n++;
       temp = temp->next; 
    }
    return n;
}

int main(){

    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);
    
    // dynmaic allocation
    a->next = b;
    b->next = c;
    c->next = d;

    display(a);
    cout<<"size of linkedlist : "<<size(a);
   
    return 0;
}