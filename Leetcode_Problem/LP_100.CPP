class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }

        if (p == nullptr || q == nullptr) {
            return false;
        }

        if (p->val != q->val) {
            return false;
        }

        bool LST = isSameTree(p->left, q->left);
        if (LST == false) return false;

        bool RST = isSameTree(p->right, q->right);
        if (RST == false) return false;

        return true;
    }
};