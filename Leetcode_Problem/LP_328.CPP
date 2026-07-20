class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode Odd(-1);
        ListNode Even(-1);

        ListNode* o = &Odd;
        ListNode* e = &Even;

        ListNode* temp = head;
        int pos = 1;

        while (temp != nullptr) {
            if (pos % 2 == 1) {
                o->next = temp;
                o = o->next;
            } else {
                e->next = temp;
                e = e->next;
            }

            temp = temp->next;
            pos++;
        }

        // Connect odd and even lists
        o->next = Even.next;
        e->next = nullptr;

        return Odd.next;
    }
};