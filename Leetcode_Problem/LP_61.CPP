class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        // base case
        if(head == nullptr || head->next == nullptr || k == 0) return head;

        // step 1 find length
        int n = 1;
        ListNode* tail = head;
        while(tail->next != nullptr){
            n++;
            tail = tail->next;
        }

        // step 2 = place temp in n-k
        if(k>=n){
            k = k%n;
        }
        if(k==0) return head;

        ListNode* temp = head;
        for(int i = 1; i < n-k; i++){
            temp = temp->next;
        }

        tail->next = head;
        head = temp->next;
        temp->next = nullptr;

        return head;
    }
};