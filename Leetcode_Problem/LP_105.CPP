class Solution {
public:
    TreeNode* build(vector<int>& preorder,int prelow, int prehigh, vector<int>& inorder, int inlow, int inhigh){

        if(prelow > prehigh || inlow > inhigh) return nullptr;

        TreeNode* root = new TreeNode(preorder[prelow]);

        int i = inlow;
        while(i<=inhigh){
            if(inorder[i]==preorder[prelow]) break;
            i++; 
        }
        int leftcount = i-inlow;
        int rightcount = inhigh-i;
        root->left = build(preorder,prelow+1,prelow+leftcount,inorder,inlow,i-1);
        root->right = build(preorder,prelow+leftcount+1,prehigh,inorder,i+1,inhigh);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return build(preorder,0,n-1,inorder,0,n-1);
    }
};