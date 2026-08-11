class Solution {
public:
    bool helper(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;

        if (p->val != q->val) return false;
        bool left = helper(p->left, q->right);
        if (left == false) return false;
        bool right = helper(p->right, q->left);
        if (right == false) return false;
        return true;
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;

        return helper(root->left, root->right);
    }
};