// method 2 (optimized)

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        // Step 1: Insert copy node after every original node
        Node* temp = head;
        while (temp != nullptr) {
            Node* copy = new Node(temp->val);
            copy->next = temp->next;
            temp->next = copy;
            temp = copy->next;
        }

        // Step 2: Copy random pointers
        temp = head;
        while (temp != nullptr) {
            if (temp->random != nullptr)
                temp->next->random = temp->random->next;

            temp = temp->next->next;
        }

        // Step 3: Separate the original and copied lists
        Node dummy(-1);
        Node* copyTail = &dummy;

        temp = head;
        while (temp != nullptr) {
            Node* copy = temp->next;

            temp->next = copy->next;   // Restore original list

            copyTail->next = copy;     // Build copied list
            copyTail = copy;

            temp = temp->next;
        }

        return dummy.next;
    }
};

// method 1 (not optimized)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        // Step 1: Deep copy (next only)
        Node dummy(-1);
        Node* td = &dummy;
        Node* temp = head;

        while (temp != nullptr) {
            Node* copy = new Node(temp->val);
            td->next = copy;
            td = td->next;
            temp = temp->next;
        }

        // Step 2: Merge (Original -> Copy)
        Node* a = head;
        Node* b = dummy.next;

        Node d(-1);
        Node* tail = &d;

        while (a != nullptr && b != nullptr) {
            // Original
            tail->next = a;
            tail = tail->next;
            a = a->next;

            // Copy
            tail->next = b;
            tail = tail->next;
            b = b->next;
        }
        tail->next = nullptr;

        // Head of merged list
        Node* mergedHead = d.next;

        // Step 3: Assign random pointers
        Node* t1 = mergedHead;

        while (t1 != nullptr) {
            Node* t2 = t1->next;   // copy node

            if (t1->random != nullptr)
                t2->random = t1->random->next;

            if (t2 != nullptr)
                t1 = t2->next;
            else
                t1 = nullptr;
        }

        // Step 4: Separate the copied list
        Node copyDummy(-1);
        Node* copyTail = &copyDummy;

        Node* curr = mergedHead;

        while (curr != nullptr) {
            Node* copy = curr->next;
            Node* nextOriginal = copy->next;

            copyTail->next = copy;
            copyTail = copy;

            curr->next = nextOriginal;

            curr = nextOriginal;
        }

        copyTail->next = nullptr;

        return copyDummy.next;
    }
};