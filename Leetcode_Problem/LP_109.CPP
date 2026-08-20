// method 3 inorder roperites 
class Solution {
public:
    TreeNode* build(ListNode*& head, int low, int high) {
        if (low > high) return nullptr;

        int mid = low + (high - low) / 2;

        TreeNode* left = build(head, low, mid - 1);

        TreeNode* root = new TreeNode(head->val);
        head = head->next;

        root->left = left;
        root->right = build(head, mid + 1, high);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        int n = 0;
        ListNode* temp = head;

        while (temp) {
            n++;
            temp = temp->next;
        }

        return build(head, 0, n - 1);
    }
};

// method 2 slow fast pointer
class Solution {
public:
    TreeNode* helper(ListNode* head) {
        if (!head) return nullptr;
        if (!head->next) return new TreeNode(head->val);

        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = nullptr;  // split the list

        TreeNode* root = new TreeNode(slow->val);

        root->left = helper(head);
        root->right = helper(slow->next);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        return helper(head);
    }
};

// method 1 low high mid approach
class Solution {
public:
    TreeNode* helper(ListNode* head, int low, int high) {
        if (low > high) return nullptr;

        int mid = low + (high - low) / 2;

        ListNode* temp = head;
        for (int i = 0; i < mid; i++) {
            temp = temp->next;
        }

        TreeNode* root = new TreeNode(temp->val);

        root->left = helper(head, low, mid - 1);
        root->right = helper(head, mid + 1, high);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        int sz = 0;
        ListNode* temp = head;

        while (temp) {
            sz++;
            temp = temp->next;
        }

        return helper(head, 0, sz - 1);
    }
};