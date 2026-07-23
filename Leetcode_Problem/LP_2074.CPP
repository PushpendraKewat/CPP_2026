class Solution {
public:
    ListNode* reverse(ListNode* head, int k){
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(k--){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prevGroupEnd = &dummy;
        ListNode* curr = head;

        int group = 1;

        while(curr){

            ListNode* groupStart = curr;

            int cnt = 0;

            while(cnt < group && curr){
                curr = curr->next;
                cnt++;
            }

            if(cnt % 2 == 0){

                ListNode* nextGroup = curr;

                prevGroupEnd->next = reverse(groupStart,cnt);

                groupStart->next = nextGroup;

                prevGroupEnd = groupStart;
            }
            else{

                prevGroupEnd = groupStart;

                for(int i=1;i<cnt;i++)
                    prevGroupEnd = prevGroupEnd->next;
            }

            group++;
        }

        return dummy.next;
    }
};