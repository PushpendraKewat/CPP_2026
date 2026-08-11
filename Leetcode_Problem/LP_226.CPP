// method 2 with function
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr) return nullptr;
        // swap left and right
        std::swap(root->left,root->right);
        
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

// method 1 (with helper function)
class Solution {
public:
    void helper(TreeNode* root){
        if(root == nullptr) return;
        // swap left and right
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        helper(root->left);
        helper(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        helper(root);
        return root;
    }
};