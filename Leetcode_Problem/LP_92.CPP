// method 1 
class Solution {
public:
    ListNode* reverse(ListNode* left, ListNode* right){
        ListNode* curr = left;
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

    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(head == nullptr || left == right)
            return head;

        int n = 0;
        ListNode* temp = head;

        while(temp != nullptr){
            n++;
            temp = temp->next;
        }

        // breaking list into 3 part

        // 1 list 1 to left-1
        ListNode dummy(0);
        dummy.next = head;

        ListNode* first = &dummy;
        for(int i = 1; i < left; i++){
            first = first->next;
        }

        // 2 left to right
        ListNode* leftNode = first->next;
        ListNode* rightNode = leftNode;

        for(int i = left; i < right; i++){
            rightNode = rightNode->next;
        }

        // 3 right + 1 to n
        ListNode* third = rightNode->next;

        // break the list
        rightNode->next = nullptr;

        // reverse middle part
        ListNode* newHead = reverse(leftNode, rightNode);

        // connect all three parts
        first->next = newHead;
        leftNode->next = third;

        return dummy.next;
    }
};