// method 2

class Solution {
public:

    ListNode* merge(ListNode* a, ListNode* b){
        ListNode c(-1);
        ListNode* tail = &c;
        while(a!=nullptr && b!=nullptr){
            if(a->val <= b->val){
                tail->next = a;
                a = a->next;
            }
            else{
                tail->next = b;
                b = b->next;
            }
            tail = tail->next; // end of any list or part 
        }
        if(a==nullptr){
            tail->next = b;
        }
        else{ // b == nullptr
            tail->next = a;
        }
        return c.next;
    }
    ListNode* sortList(ListNode* head) {

        if(head==nullptr || head->next==nullptr) return head;

        ListNode* slow = head;
        ListNode* fast = head;
        // ListNode* fast = head->next;

        // find middle
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next; // slow is now at middle
        slow->next = nullptr;

        // now ll divide in two part
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);

        // now merge
        return merge(left,right);
    }
};

// method 1
class Solution {
public:

    ListNode* merge(ListNode* a, ListNode* b){
        ListNode c(-1);
        ListNode* tail = &c;
        while(a!=nullptr && b!=nullptr){
            if(a->val <= b->val){
                tail->next = a;
                a = a->next;
            }
            else{
                tail->next = b;
                b = b->next;
            }
            tail = tail->next; // end of any list or part 
        }
        if(a==nullptr){
            tail->next = b;
        }
        else{ // b == nullptr
            tail->next = a;
        }
        return c.next;
    }
    ListNode* sortList(ListNode* head) {

        if(head==nullptr || head->next==nullptr) return head;
        
        ListNode* slow = head;
        ListNode* fast = head->next;

        // find middle
        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next; // slow is now at middle
        slow->next = nullptr;

        // now ll divide in two part
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);

        // now merge
        return merge(left,right);
    }
};