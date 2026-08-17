#include <iostream>
#include <algorithm>
#include <climits>
#include<vector>

using std::cout;
using std::endl;
using std::vector;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};

void leftSideView(TreeNode* root, int level, vector<int>& ans) {
    if (root == nullptr) return;

    if (level == ans.size())
        ans.push_back(root->val);

    leftSideView(root->left, level + 1, ans);
    leftSideView(root->right, level + 1, ans);
}

int main(){

    TreeNode* a = new TreeNode(1);
    TreeNode* b = new TreeNode(2);
    TreeNode* c = new TreeNode(3);
    TreeNode* d = new TreeNode(4);
    TreeNode* e = new TreeNode(5);
    TreeNode* f = new TreeNode(6);
    TreeNode* g = new TreeNode(7);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;

    vector<int> ans;
    leftSideView(a,0,ans);
    for(int x : ans){
        cout<<x<<" ";
    }
    return 0;
}