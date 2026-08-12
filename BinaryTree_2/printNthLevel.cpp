#include <iostream>

using std::cout;
using std::endl;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};

void NthLevel(TreeNode* root, int curr, int level) {
    if (root == nullptr) return;

    if (curr == level) {
        cout << root->val << " ";
        return;
    }

    NthLevel(root->left,curr+1,level);
    NthLevel(root->right,curr+1,level);
}

int main() {
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

    int n = 3;
    NthLevel(a,1,n);

    return 0;
}