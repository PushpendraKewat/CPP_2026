class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            n++;
            temp = temp->next;
        }
        
        // breaks the list into k parts
        vector<ListNode*> ans(k, nullptr);
        int size = n / k;
        int rem = n % k;
        temp = head;
        
        for (int i = 0; i < k; i++) {
            ListNode* c = temp;
            int current_size = size + (rem-- > 0 ? 1 : 0);
            for (int j = 0; j < current_size - 1; j++) {
                if (temp != nullptr) temp = temp->next;
            }
            if (temp != nullptr) {
                ListNode* next = temp->next;
                temp->next = nullptr;
                temp = next;
            }
            ans[i] = c;
        }
        
        return ans;
    }
};