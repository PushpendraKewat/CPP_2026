// method 1 (one pass solution(slow & fast pointer))
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Move fast n steps ahead
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // If fast becomes nullptr, delete the head
        if (fast == nullptr) {
            return head->next;
        }

        // Move both pointers
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* del = slow->next;
        slow->next = del->next;
        delete del;

        return head;
    }
};




// method 2 two loops
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* temp = head;

        while (temp != nullptr) {
            len++;
            temp = temp->next;
        }

        // Position from the start (1-based)
        int m = len - n + 1;

        // If head is to be deleted
        if (m == 1) {
            return head->next;
        }

        temp = head;

        // Move to the node just before the one to delete
        for (int i = 1; i <= m - 2; i++) {
            temp = temp->next;
        }

        temp->next = temp->next->next;

        return head;
    }
};