#include <iostream>
#include <algorithm>

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

int height(TreeNode* root) {
    if (root == nullptr) return 0;

    return 1 + std::max(height(root->left), height(root->right));
}

void printLevel(TreeNode* root, int level) {
    if (root == nullptr) return;

    if (level == 1) {
        cout << root->val << " ";
        return;
    }

    printLevel(root->left, level - 1);
    printLevel(root->right, level - 1);
}

void levelOrder(TreeNode* root) {
    int h = height(root);

    for (int i = 1; i <= h; i++) {
        printLevel(root, i);
    }
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

    levelOrder(a);

    return 0;
}