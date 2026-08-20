// method 2 sum pass by reference
class Solution {
public:
    void inorder(TreeNode* root, int& sum) {
        if (root == nullptr) return;

        inorder(root->right, sum);

        sum += root->val;
        root->val = sum;

        inorder(root->left, sum);
    }

    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        inorder(root, sum);
        return root;
    }
};

// method 1 global varible reverse inorder
class Solution {
public:
    int sum = 0;
    void inorder(TreeNode* root){
        if(root==nullptr) return;
        inorder(root->right);
        sum += root->val;
        inorder(root->left);
    }
    TreeNode* bstToGst(TreeNode* root) {
        inorder(root);
        return root;
    }
};