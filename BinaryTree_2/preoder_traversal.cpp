#include <iostream>
#include <algorithm>
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

// Preorder Traversal
void preorder(TreeNode* root){
    if(root == nullptr) return;

    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
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

    cout << "Preorder : ";
    preorder(a);

    return 0;
}