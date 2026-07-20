// method 3 divide and conquer and merge two list
class Solution {
public:
    // Merge two sorted linked lists
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode dummy(-1);
        ListNode* tail = &dummy;

        while (a != nullptr && b != nullptr) {
            if (a->val <= b->val) {
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }

        // Attach remaining nodes
        if (a != nullptr)
            tail->next = a;
        else
            tail->next = b;

        return dummy.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        int interval = 1;

        // Continue until only one merged list remains
        while (interval < lists.size()) {

            // Merge pairs of lists
            for (int i = 0; i + interval < lists.size(); i += 2 * interval) {
                lists[i] = merge(lists[i], lists[i + interval]);
            }

            // Double the interval for the next round
            interval *= 2;
        }

        return lists[0];
    }
};

// method 2
class Solution {
public:
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode dummy(-1);
        ListNode* tail = &dummy;

        while (a != nullptr && b != nullptr) {
            if (a->val <= b->val) {
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }

            tail = tail->next;
        }

        // Attach remaining nodes
        if (a != nullptr)
            tail->next = a;
        else
            tail->next = b;

        return dummy.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        while (lists.size() > 1) {
            ListNode* a = lists[0];
            lists.erase(lists.begin());

            ListNode* b = lists[0];
            lists.erase(lists.begin());

            ListNode* c = merge(a, b);
            lists.push_back(c);
        }

        return lists[0];
    }
};


// method 1
class Solution {    // using two merge
                    // sorted apporach
public:

    ListNode* merge(ListNode* list1, ListNode* list2) {

        ListNode dummy(-1);
        ListNode* tail = &dummy;

        // Traverse both lists
        while (list1 != nullptr && list2 != nullptr) {

            if (list1->val <= list2->val) {
                tail->next = list1;      
                list1 = list1->next; 
            }
            else {
                tail->next = list2;      
                list2 = list2->next;  
            }

            // Move tail to the last node
            tail = tail->next;
        }

        // Attach the remaining nodes
        if (list1 != nullptr)
            tail->next = list1;
        else
            tail->next = list2;

        // Return the merged list (skip dummy node)
        return dummy.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return nullptr;
        while(lists.size()>1){
            ListNode* a = lists[lists.size()-1];
            lists.pop_back();
            ListNode* b = lists[lists.size()-1];
            lists.pop_back();
            ListNode* c = merge(a,b);
            lists.push_back(c);
        }
        return lists[0];
    }
};