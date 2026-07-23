// method 2 (optimized)
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return {-1, -1};

        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = head->next->next;

        int idx = 1;

        int first = -1;      // Index of first critical point
        int last = -1;       // Index of last critical point
        int prevCritical = -1; // Index of previous critical point
        int minDist = INT_MAX;

        while (next != nullptr) {
            if ((curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val)) {

                if (first == -1) {
                    // First critical point
                    first = idx;
                } else {
                    // Compute minimum distance
                    minDist = min(minDist, idx - prevCritical);
                }

                prevCritical = idx;
                last = idx;
            }

            prev = curr;
            curr = next;
            next = next->next;
            idx++;
        }

        if (first == last)
            return {-1, -1};

        return {minDist, last - first};
    }
};

// METHOD 1
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // finding maxDistance
        int idx = 1;
        int fidx = -1;
        int sidx = -1;
        ListNode* a = head;
        ListNode* b = head->next;
        ListNode* c = head->next->next;
        if(c==nullptr) return {-1,-1};
        while(c!=nullptr){
            if((b->val > a->val && b->val > c->val) || (b->val < a->val && b->val < c->val)){
                if(fidx == -1){
                    fidx = idx;
                }
                else{
                    sidx  = idx;
                }
            }
            a = a->next;
            b = b->next;
            c = c->next;
            idx++;
        }
        if(sidx == -1) return {-1,-1};
        int maxDistance = sidx - fidx;
        // finding minDistance;
        int minDistance = INT_MAX;
        fidx = -1;
        sidx = -1;
        idx = 1;
        a = head;
        b = head->next;
        c = head->next->next;
        while(c!=nullptr){
            if((b->val > a->val && b->val > c->val) || (b->val < a->val && b->val < c->val)){
                fidx = sidx;
                sidx = idx;
                if(fidx!=-1){
                    int currDistance = sidx - fidx;
                    minDistance = min(minDistance,currDistance);
                }
            }
            a = a->next;
            b = b->next;
            c = c->next;
            idx++;
        }
        return {minDistance,maxDistance};
    }
};