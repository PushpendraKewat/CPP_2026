class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {

        ListNode dummy(-1);
        ListNode* curr = head;

        while (curr != nullptr) {

            ListNode* next = curr->next;

            // Find insertion position
            ListNode* prev = &dummy;

            while (prev->next != nullptr &&
                   prev->next->val < curr->val) {
                prev = prev->next;
            }

            // Insert curr
            curr->next = prev->next;
            prev->next = curr;

            curr = next;
        }

        return dummy.next;
    }
};