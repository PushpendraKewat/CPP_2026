// method 1 (recurive)
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr || root->val == val) return root;
        if (val < root->val){
            return searchBST(root->left, val);
        }else{
            return searchBST(root->right, val);
        }
    }
};

// method 2 (iterative)
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root != nullptr && root->val != val) {
            if (val < root->val)
                root = root->left;
            else
                root = root->right;
        }
        return root;
    }
};