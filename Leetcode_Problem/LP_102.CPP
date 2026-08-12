// method 2

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            ans.push_back(level);
        }

        return ans;
    }
};


// method 1
class Solution {
public:
    int height(TreeNode* root) {
        if (root == nullptr) return 0;

        return 1 + max(height(root->left), height(root->right));
    }

    void printLevel(TreeNode* root, int level, vector<int>& curr) {
        if (root == nullptr) return;

        if (level == 1) {
            curr.push_back(root->val);
            return;
        }

        printLevel(root->left, level - 1, curr);
        printLevel(root->right, level - 1, curr);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        int h = height(root);

        for (int i = 1; i <= h; i++) {
            vector<int> curr;
            printLevel(root, i, curr);
            ans.push_back(curr);
        }

        return ans;
    }
};