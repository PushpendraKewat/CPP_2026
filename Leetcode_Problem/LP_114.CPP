// method 3 morris traversal
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;

        while (curr != nullptr) {
            if (curr->left != nullptr) {
                TreeNode* pred = curr->left;

                while (pred->right != nullptr) {
                    pred = pred->right;
                }

                pred->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }

            curr = curr->right;
        }
    }
};

// method 2 recursion 
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==nullptr) return;
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        root->left = nullptr;
        root->right = nullptr;
        flatten(l);
        flatten(r);
        root->right = l;
        TreeNode* temp = root;
        while(temp->right!=nullptr){
            temp = temp->right;
        }
        temp->right = r;
    }
};


// METHOD 1 PREORDER RECURSION
class Solution {
public:
    vector<TreeNode*> preorder(TreeNode* root, vector<TreeNode*>& ans){
        if(root==nullptr) return ans;
        ans.push_back(root);
        preorder(root->left,ans);
        preorder(root->right,ans);
        return ans;
    }
    void flatten(TreeNode* root) {
        vector<TreeNode*> ans;
        preorder(root,ans);
        int n = ans.size();
        for(int i=0;i<n-1;i++){
            ans[i]->right = ans[i+1];
            ans[i]->left = nullptr;
        }
    }
};