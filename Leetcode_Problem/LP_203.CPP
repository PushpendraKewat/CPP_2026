class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        // Special handling for head node(s)
        while (head != nullptr && head->val == val) {
            ListNode* del = head;
            head = head->next;
            delete del;
        }

        // If list becomes empty
        if (head == nullptr)
            return head;

        ListNode* temp = head;

        while (temp->next != nullptr) {

            if (temp->next->val == val) {
                ListNode* del = temp->next;
                temp->next = del->next;
                delete del;
            }
            else {
                temp = temp->next;
            }
        }

        return head;
    }
};