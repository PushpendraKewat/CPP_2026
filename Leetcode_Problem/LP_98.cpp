// method 3 best solution
class Solution {
public:
    bool helper(TreeNode* root, long long low, long long high) {
        if (root == nullptr) return true;

        if (root->val <= low || root->val >= high)
            return false;

        bool leftBST = helper(root->left, low, root->val);
        bool rightBST = helper(root->right, root->val, high);

        return leftBST && rightBST;
    }

    bool isValidBST(TreeNode* root) {
        return helper(root, LLONG_MIN, LLONG_MAX);
    }
};

// method 2 (using bst inorder traversal properties)
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& ans) {
        if (root == nullptr) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    bool isValidBST(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        for (int i = 0; i < ans.size() - 1; i++) {
            if (ans[i] >= ans[i + 1]) {
                return false;
            }
        }
        return true;
    }
};


// method 1 brute force
class Solution {
public:
    int leftmax(TreeNode* root) {
        while (root->right)
            root = root->right;
        return root->val;
    }

    int rightmin(TreeNode* root) {
        while (root->left)
            root = root->left;
        return root->val;
    }

    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;

        if (root->left && leftmax(root->left) >= root->val)
            return false;

        if (root->right && rightmin(root->right) <= root->val)
            return false;

        return isValidBST(root->left) &&
               isValidBST(root->right);
    }
};