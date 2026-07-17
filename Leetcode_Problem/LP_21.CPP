// method 1
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode dummy(-1);
        ListNode* tail = &dummy;

        // Traverse both lists
        while (list1 != nullptr && list2 != nullptr) {

            if (list1->val <= list2->val) {
                tail->next = list1;      
                list1 = list1->next; 
            }
            else {
                tail->next = list2;      
                list2 = list2->next;  
            }

            // Move tail to the last node
            tail = tail->next;
        }

        // Attach the remaining nodes
        if (list1 != nullptr)
            tail->next = list1;
        else
            tail->next = list2;

        // Return the merged list (skip dummy node)
        return dummy.next;
    }
};