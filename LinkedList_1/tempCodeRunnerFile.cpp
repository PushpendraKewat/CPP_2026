
        this->val = val;
        this->next = nullptr;
    
// delete at tail

void deleteAtTail(){
        if(size==0){
                cout<<"LinkedLisr is empty ";
                return;
        }
        Node* temp = head;
        while(temp->next!-nullptr){
                temp = temp->next;
        }
        temp->next = nullptr;
        tail = temp;
        size--;
}

void deleteAtIndex(int idx){
        if(idx<0 || idx>=size){
                cout<<"invalid index";
                return -1;
        }
        else if(idx==0){
                return deleteAtHead();
        }
        else if(idx==size-1){
                return deleteAtTail();
        }

        Node* temp = head;
        for(int i=1;i<idx;i++){
                temp = temp->next;
        }
        temp->next = temp->next->next;
        size--;
}