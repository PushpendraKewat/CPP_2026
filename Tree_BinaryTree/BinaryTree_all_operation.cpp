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

// Inorder Traversal
void inorder(TreeNode* root){
    if(root == nullptr) return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Postorder Traversal
void postorder(TreeNode* root){
    if(root == nullptr) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

// Number of nodes
int size(TreeNode* root){
    if(root == nullptr) return 0;

    return 1 + size(root->left) + size(root->right);
}

// Sum of all nodes
int sum(TreeNode* root){
    if(root == nullptr) return 0;

    return root->val + sum(root->left) + sum(root->right);
}

// Product of all nodes
int product(TreeNode* root){
    if(root == nullptr) return 1;

    return root->val * product(root->left) * product(root->right);
}

// Maximum value
int max(TreeNode* root){
    if(root == nullptr) return INT_MIN;

    return std::max(root->val,
                    std::max(max(root->left), max(root->right)));
}

// Minimum value
int min(TreeNode* root){
    if(root == nullptr) return INT_MAX;

    return std::min(root->val,
                    std::min(min(root->left), min(root->right)));
}

// Height / Levels
int level(TreeNode* root){
    if(root == nullptr) return 0;

    return 1 + std::max(level(root->left), level(root->right));
}

// Count leaf nodes
int leafNodes(TreeNode* root){
    if(root == nullptr) return 0;

    if(root->left == nullptr && root->right == nullptr)
        return 1;

    return leafNodes(root->left) + leafNodes(root->right);
}

// Count internal nodes
int internalNodes(TreeNode* root){
    if(root == nullptr) return 0;

    if(root->left == nullptr && root->right == nullptr)
        return 0;

    return 1 + internalNodes(root->left) + internalNodes(root->right);
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

    cout << "\nInorder : ";
    inorder(a);

    cout << "\nPostorder : ";
    postorder(a);

    cout << "\n\nSize = " << size(a);
    cout << "\nSum = " << sum(a);
    cout << "\nProduct = " << product(a);
    cout << "\nMaximum = " << max(a);
    cout << "\nMinimum = " << min(a);
    cout << "\nHeight = " << level(a);
    cout << "\nLeaf Nodes = " << leafNodes(a);
    cout << "\nInternal Nodes = " << internalNodes(a);

    return 0;
}