class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                ListNode* temp = head;
                while(slow!=temp){
                    slow = slow->next;
                    temp = temp->next;
                }
                return slow; // or return temp
            }
        }
        return nullptr;
    }
};