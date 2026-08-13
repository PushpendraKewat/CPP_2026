// method 2 itervative
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr) return ans;

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()) {
            TreeNode* temp = st.top();
            st.pop();

            ans.push_back(temp->val);

            if(temp->left) st.push(temp->left);
            if(temp->right) st.push(temp->right);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// method 1 recursive
class Solution {
public:
    void postorder(TreeNode* root, vector<int>& ans){
        if(root==nullptr) return;
        postorder(root->left,ans);
        postorder(root->right,ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root,ans);
        return ans;
    }
};