// method 2 dfs
class Solution {
public:
    void dfs(TreeNode* root, int level, vector<int>& ans) {
        if (root == nullptr) return;

        if (level == ans.size()) {
            ans.push_back(root->val);
        }

        dfs(root->right, level + 1, ans);
        dfs(root->left, level + 1, ans);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        dfs(root, 0, ans);
        return ans;
    }
};

// method 1 bfs 
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                if (i == size - 1) {
                    ans.push_back(curr->val);
                }

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }

        return ans;
    }
};