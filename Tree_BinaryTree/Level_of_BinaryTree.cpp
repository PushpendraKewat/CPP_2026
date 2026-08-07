#include<iostream>
#include<algorithm>
#include <climits>

using std::cout;
using std::endl;

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

void DisplayTree(TreeNode* root){
    if(root==nullptr) return;
    cout<<root->val<<" ";
    DisplayTree(root->left);
    DisplayTree(root->right);
}

int levels(TreeNode* root){
    if(root == nullptr)
        return 0;

    return 1 + std::max(levels(root->left), levels(root->right));
}

int main(){
    TreeNode* a = new TreeNode(1);
    TreeNode* b = new TreeNode(2);
    TreeNode* c = new TreeNode(3);
    TreeNode* d = new TreeNode(4);
    TreeNode* e = new TreeNode(5);
    TreeNode* f = new TreeNode(6);
    TreeNode* g = new TreeNode(7);
    TreeNode* h = new TreeNode(8);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;
    g->left = h;

    DisplayTree(a);
    cout<<endl;
    cout<<levels(a);
    return 0;
}