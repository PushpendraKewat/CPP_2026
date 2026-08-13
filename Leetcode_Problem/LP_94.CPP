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