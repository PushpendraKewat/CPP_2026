class Solution {
public:
    int helper(TreeNode* root, long long sum){
        if(root == nullptr) return 0;

        int count = 0;

        if(root->val == sum)
            count++;

        count += helper(root->left, sum - root->val);
        count += helper(root->right, sum - root->val);

        return count;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return 0;

        int count = helper(root, targetSum);

        count += pathSum(root->left, targetSum)
              + pathSum(root->right, targetSum);

        return count;
    }
};