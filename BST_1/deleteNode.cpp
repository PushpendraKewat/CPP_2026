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

TreeNode* insert(TreeNode* root, int val) {
    if (root == nullptr)
        return new TreeNode(val);

    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

TreeNode* findMin(TreeNode* root) {
    while (root->left)
        root = root->left;
    return root;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr)
        return nullptr;

    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    }
    else {
        // No child
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }

        // One child
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }

        if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        // Two children
        TreeNode* succ = findMin(root->right);
        root->val = succ->val;
        root->right = deleteNode(root->right, succ->val);
    }

    return root;
}

void inorder(TreeNode* root) {
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    int values[] = {10, 5, 20, 2, 8, 15, 25, 4, 12};

    TreeNode* root = nullptr;

    for (int x : values)
        root = insert(root, x);

    cout << "Inorder before deletion: ";
    inorder(root);

    root = deleteNode(root, 10);

    cout << "\nInorder after deleting 10: ";
    inorder(root);

    cout << endl;

    return 0;
}