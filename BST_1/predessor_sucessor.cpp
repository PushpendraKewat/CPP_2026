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

void findPreSuc(TreeNode* root, TreeNode*& pre, TreeNode*& suc, int key) {
    if (root == nullptr) return;

    if (root->val == key) {

        if (root->left) {
            TreeNode* temp = root->left;
            while (temp->right)
                temp = temp->right;
            pre = temp;
        }

        if (root->right) {
            TreeNode* temp = root->right;
            while (temp->left)
                temp = temp->left;
            suc = temp;
        }

        return;
    }

    if (key < root->val) {
        suc = root;
        findPreSuc(root->left, pre, suc, key);
    } else {
        pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
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

    TreeNode* pre = nullptr;
    TreeNode* suc = nullptr;

    findPreSuc(root, pre, suc, key);

    cout << "Key: " << key << endl;

    if (pre)
        cout << "Predecessor: " << pre->val << endl;
    else
        cout << "Predecessor: None" << endl;

    if (suc)
        cout << "Successor: " << suc->val << endl;
    else
        cout << "Successor: None" << endl;

    return 0;
}