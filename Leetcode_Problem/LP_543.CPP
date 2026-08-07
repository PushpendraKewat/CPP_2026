// method 2 (local variable)

class Solution {
public:
    int levels(TreeNode* root){
        if(root == nullptr) return 0;

        return 1 + std::max(levels(root->left), levels(root->right));
    }

    void helper(TreeNode* root, int &mxDia){
        if(root == nullptr) return;

        int dia = levels(root->left) + levels(root->right);
        mxDia = std::max(mxDia, dia);

        helper(root->left, mxDia);
        helper(root->right, mxDia);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int mxDia = 0;
        helper(root, mxDia);
        return mxDia;
    }
};

// method 1 (global varivable)
class Solution {
public:
    int ans = 0; 
    int levels(TreeNode* root){
        if(root == nullptr) return 0;
        
        int leftlevels = levels(root->left);
        int rightlevels = levels(root->right);
        
        // Calculate the diameter for the current node
        int mydia = leftlevels + rightlevels;
        ans = max(ans, mydia);
        
        // Return the height of the tree
        return 1 + max(leftlevels, rightlevels);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        levels(root);
        return ans;
    }
};