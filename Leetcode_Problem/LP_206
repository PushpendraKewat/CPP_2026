// method 3 (recursion)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Base case
        if (head == nullptr || head->next == nullptr)
            return head;

        // Reverse the rest of the list
        ListNode* newHead = reverseList(head->next);

        // Reverse the current link
        head->next->next = head;
        head->next = nullptr;

        // Return the new head
        return newHead;
    }
};

// method 2 (iterative approach)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* NEXT = nullptr;

        while(curr!=nullptr){
            NEXT = curr->next; // Save next node
            curr->next = prev; // Reverse the link
            prev = curr;    // Move prev forward
            curr = NEXT;   // Move curr forward
        } 
        return prev;
    }
};






// method 1 (brute force)
class Solution {
public:
    ListNode* getNode(ListNode* head,int idx){
        ListNode* temp = head;
        for(int i=1;i<=idx;i++){
            temp = temp->next;
        }
        return temp;
    }

    ListNode* reverseList(ListNode* head) {
        int n = 0;
        ListNode* temp = head;
        while(temp!=nullptr){
            n++;
            temp = temp->next;
        }
        int i = 0;
        int j = n-1;
        while(i<j){
            ListNode* left = getNode(head,i);
            ListNode* right = getNode(head,j);
            // swap left->val and right->val
            int temp = left->val;
            left->val = right->val;
            right->val = temp;
            i++;
            j--;
        }
        return head;
    }
};