// method 2 iterative
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr) return ans;

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()) {
            TreeNode* temp = st.top();
            st.pop();

            ans.push_back(temp->val);

            if(temp->right) st.push(temp->right);
            if(temp->left) st.push(temp->left);
        }

        return ans;
    }
};


// method 1 recurisve
class Solution {
public:
    void preorder(TreeNode* root, vector<int>& ans) {
        if (root == nullptr) return;

        ans.push_back(root->val);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
};