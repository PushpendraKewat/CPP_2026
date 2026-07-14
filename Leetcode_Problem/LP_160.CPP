// method 2
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        // Find lengths of both lists
        int len1 = 0, len2 = 0;
        ListNode* tempA = headA;
        ListNode* tempB = headB;

        while (tempA != nullptr) {
            len1++;
            tempA = tempA->next;
        }

        while (tempB != nullptr) {
            len2++;
            tempB = tempB->next;
        }
        tempA = headA;
        tempB = headB;

        // calculate diffeence move
        if(len1>len2){
            int diff = len1 - len2;
            for(int i=0;i<diff;i++){
                tempA = tempA->next;
            }
        }
        else{ // now len2>len1
            int diff = len2-len1;
            for(int i=0;i<diff;i++){
                tempB = tempB->next;
            }
        }
        // move both pointer
        while(tempA!=tempB){
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return tempA;
    }
};

//metthod 1
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        // Find lengths of both lists
        int len1 = 0, len2 = 0;
        ListNode* tempA = headA;
        ListNode* tempB = headB;

        while (tempA != nullptr) {
            len1++;
            tempA = tempA->next;
        }

        while (tempB != nullptr) {
            len2++;
            tempB = tempB->next;
        }
        tempA = headA;
        tempB = headB;

        // calculate diffeence move
        if(len1>len2){
            int diff = len1 - len2;
            for(int i=0;i<diff;i++){
                tempA = tempA->next;
            }
        }
        else{ // now len2>len1
            int diff = len2-len1;
            for(int i=0;i<diff;i++){
                tempB = tempB->next;
            }
        }
        // move both pointer
        while(tempA!=tempB){
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return tempA;
    }
};