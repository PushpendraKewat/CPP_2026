class Solution {
public:
    int levels(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + max(levels(root->left), levels(root->right));
    }

    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;

        int lh = levels(root->left);
        int rh = levels(root->right);

        if (abs(lh - rh) > 1) return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }
};