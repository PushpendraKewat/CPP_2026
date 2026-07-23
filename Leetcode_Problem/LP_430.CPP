class Solution {
public:
    Node* flatten(Node* head) {
        Node* temp = head;

        while (temp != nullptr) {

            if (temp->child != nullptr) {

                Node* a = temp->next;
                Node* c = temp->child;

                temp->child = nullptr;

                c = flatten(c);

                temp->next = c;
                c->prev = temp;

                while (c->next != nullptr)
                    c = c->next;

                c->next = a;

                if (a != nullptr)
                    a->prev = c;
            }

            temp = temp->next;
        }

        return head;
    }
};