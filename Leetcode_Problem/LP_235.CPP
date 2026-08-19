class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if ((p->val <= root->val && q->val >= root->val) ||
            (q->val <= root->val && p->val >= root->val)) {
            return root;
        }
        else if (p->val < root->val && q->val < root->val) {
            // left
            return lowestCommonAncestor(root->left, p, q);
        }
        else { // p and q are > root->val
            // right
            return lowestCommonAncestor(root->right, p, q);
        }
    }
};