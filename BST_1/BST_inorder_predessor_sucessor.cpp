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

TreeNode* inorderPredecessor(TreeNode* root, int key) {
    TreeNode* pred = nullptr;

    while (root) {
        if (key > root->val) {
            pred = root;
            root = root->right;
        } else {
            root = root->left;
        }
    }

    return pred;
}

TreeNode* inorderSuccessor(TreeNode* root, int key) {
    TreeNode* succ = nullptr;

    while (root) {
        if (key < root->val) {
            succ = root;
            root = root->left;
        } else {
            root = root->right;
        }
    }

    return succ;
}

int main() {
    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(10);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(15);
    root->right->left = new TreeNode(25);
    root->right->right = new TreeNode(40);

    int key = 20;

    TreeNode* pred = inorderPredecessor(root, key);
    TreeNode* succ = inorderSuccessor(root, key);

    if (pred)
        cout << "Predecessor: " << pred->val << endl;
    else
        cout << "Predecessor: None" << endl;

    if (succ)
        cout << "Successor: " << succ->val << endl;
    else
        cout << "Successor: None" << endl;

    return 0;
}       