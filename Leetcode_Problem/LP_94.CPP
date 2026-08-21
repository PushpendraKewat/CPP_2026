// method 3 Morris Traversal
class Solution {
public:
    // Morris Traversal
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;
        while(curr!=nullptr){
           if(curr->left!=nullptr){ // find predessor
                TreeNode* pred = curr->left;
                while(pred->right!=nullptr && pred->right!=curr){
                    pred = pred->right;
                }
                if(pred->right==nullptr){ // link
                    pred->right = curr;
                    curr = curr->left;
                }
                if(pred->right==curr){ // unlink
                    pred->right = nullptr;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
           }
           else{ // curr->left == nullptr
                ans.push_back(curr->val);
                curr = curr->right;
           }

        }
        return ans;
    }
};

// method 2 iterative
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* temp = root;
        while(temp != nullptr || !st.empty()) {
            while(temp != nullptr) {
                st.push(temp);
                temp = temp->left;
            }
            temp = st.top();
            st.pop();
            ans.push_back(temp->val);
            temp = temp->right;
        }
        return ans;
    }
};


// methhod 1 recusion
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& ans) {
        if (root == nullptr) return;

        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
};