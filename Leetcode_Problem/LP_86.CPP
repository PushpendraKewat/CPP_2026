class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        ListNode a(-1);
        ListNode b(-1);

        ListNode* small = &a;
        ListNode* large = &b;

        ListNode* temp = head;
        

        while (temp != nullptr) {

            if (temp->val < x) {
                small->next = temp;
                small = small->next;
            } else {
                large->next = temp;
                large = large->next;
            }

            temp = temp->next;
        }

        large->next = nullptr;   // End large list
        small->next = b.next;    // Connect lists

        return a.next;
    }
};