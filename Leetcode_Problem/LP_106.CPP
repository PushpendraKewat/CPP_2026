class Solution {
public:
    TreeNode* build(vector<int>& inorder, int inlow, int inhigh,vector<int>& postorder, int postlow, int posthigh){

        if(inlow > inhigh || postlow > posthigh) return nullptr;
        TreeNode* root = new TreeNode(postorder[posthigh]);

        int i = inlow;
        while(i<=inhigh){
            if(inorder[i]==postorder[posthigh]){
                break;
            }
            i++;
        }
        int leftcount = i - inlow;
        root->left = build(inorder,inlow,i-1,postorder,postlow,postlow+leftcount-1);
        root->right = build(inorder,i+1,inhigh,postorder,postlow+leftcount,posthigh-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        return build(inorder,0,n-1,postorder,0,n-1);
    }
};