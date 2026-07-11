class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Move fast k steps ahead
        for (int i = 1; i <= k; i++) {
            fast = fast->next;
        }

        // Save kth node from the beginning
        ListNode* first = head;
        for (int i = 1; i < k; i++) {
            first = first->next;
        }

        // Find kth node from the end
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        // slow is kth node from the end
        swap(first->val, slow->val);

        return head;
    }
};