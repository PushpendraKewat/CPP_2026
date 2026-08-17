class Solution {
public:
    TreeNode* build(vector<int>& preorder, int prelow, int prehigh,
                    vector<int>& postorder, int postlow, int posthigh) {

        if (prelow > prehigh) return nullptr;

        TreeNode* root = new TreeNode(preorder[prelow]);

        if (prelow == prehigh) return root;

        int leftRoot = preorder[prelow + 1];

        int i = postlow;
        while (i <= posthigh) {
            if (postorder[i] == leftRoot) break;
            i++;
        }

        int leftcount = i - postlow + 1;

        root->left = build(preorder,
                           prelow + 1,
                           prelow + leftcount,
                           postorder,
                           postlow,
                           i);

        root->right = build(preorder,
                            prelow + leftcount + 1,
                            prehigh,
                            postorder,
                            i + 1,
                            posthigh - 1);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();

        return build(preorder, 0, n - 1,
                     postorder, 0, n - 1);
    }
};