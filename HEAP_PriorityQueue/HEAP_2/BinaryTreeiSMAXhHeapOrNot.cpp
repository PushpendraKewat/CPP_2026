#include<iostream>

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

bool isMaxOrder(TreeNode* root){
    if(root == nullptr) return true;

    // Leaf node
    if(root->left == nullptr && root->right == nullptr){
        return true;
    }

    // Only left child
    if(root->right == nullptr){
        return root->val >= root->left->val;
    }

    return root->val >= root->left->val &&
           root->val >= root->right->val &&
           isMaxOrder(root->left) &&
           isMaxOrder(root->right);
}

bool isCBT(TreeNode* root, int index, int totalNodes){
    if(root == nullptr) return true;

    if(index >= totalNodes) return false;

    return isCBT(root->left, 2 * index + 1, totalNodes) &&
           isCBT(root->right, 2 * index + 2, totalNodes);
}

int countNodes(TreeNode* root){
    if(root == nullptr) return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

bool isHeap(TreeNode* root){
    int totalNodes = countNodes(root);

    return isCBT(root, 0, totalNodes) &&
           isMaxOrder(root);
}

int main(){
    TreeNode* a = new TreeNode(20);
    TreeNode* b = new TreeNode(18);
    TreeNode* c = new TreeNode(15);
    TreeNode* d = new TreeNode(10);
    TreeNode* e = new TreeNode(12);
    TreeNode* f = new TreeNode(14);
    TreeNode* g = new TreeNode(13);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;

    if(isHeap(a)){
        cout << "Given binary tree is a Max Heap" << endl;
    }
    else{
        cout << "Given binary tree is NOT a Max Heap" << endl;
    }

    return 0;
}