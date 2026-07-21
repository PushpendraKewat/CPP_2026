// method 2
class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (curr != nullptr) {
            ListNode* Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }

        return prev;
    }

    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return;

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode* second = reverse(slow->next);
        slow->next = nullptr;

        // Merge both halves
        ListNode* first = head;

        while (second != nullptr) {
            ListNode* t1 = first->next;
            ListNode* t2 = second->next;

            first->next = second;
            second->next = t1;

            first = t1;
            second = t2;
        }
    }
}

// method 1
class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* Next = nullptr;

        while(curr != nullptr){
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = slow->next;
        slow->next = nullptr;

        ListNode* r = reverse(second);

        ListNode c(-1);
        ListNode* tc = &c;

        ListNode* a = head;
        ListNode* b = r;

        while(a != nullptr && b != nullptr){
            ListNode* ta = a->next;
            ListNode* tb = b->next;

            tc->next = a;
            tc = tc->next;

            tc->next = b;
            tc = tc->next;

            a = ta;
            b = tb;
        }

        if(a != nullptr)
            tc->next = a;
    }
};