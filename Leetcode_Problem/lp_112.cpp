class Solution {
public:
    bool solve(TreeNode* root, int targetSum, int sum){
        if(root == nullptr) return false;
        
        sum += root->val;
        
        if(root->left == nullptr && root->right == nullptr){
            return sum == targetSum;
        }

        bool leftans = solve(root->left, targetSum, sum);
        bool rightans = solve(root->right, targetSum, sum);
        
        return leftans || rightans;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;
        return solve(root, targetSum, 0);
    }
};
