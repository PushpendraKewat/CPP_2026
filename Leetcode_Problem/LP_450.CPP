class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;

        if (root->val > key) {
            root->left = deleteNode(root->left, key);
        }
        else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        }
        else {
            // 0 or 1 child
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // 2 children
            TreeNode* succ = root->right;
            while (succ->left!=nullptr){
                succ = succ->left;
            }  
            root->val = succ->val;
            root->right = deleteNode(root->right, succ->val);
        }
        return root;
    }
};