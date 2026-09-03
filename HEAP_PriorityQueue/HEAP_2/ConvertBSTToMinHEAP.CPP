#include<iostream>
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

void inorder(TreeNode* root, vector<int>& v){
    if(root == nullptr) return;

    inorder(root->left, v);
    v.push_back(root->val);
    inorder(root->right, v);
}

void preorderFill(TreeNode* root, vector<int>& v, int& idx){
    if(root == nullptr) return;

    root->val = v[idx++];
    preorderFill(root->left, v, idx);
    preorderFill(root->right, v, idx);
}

void preorderPrint(TreeNode* root){
    if(root == nullptr) return;

    cout << root->val << " ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

int main(){
    TreeNode* a = new TreeNode(10);
    TreeNode* b = new TreeNode(5);
    TreeNode* c = new TreeNode(16);
    TreeNode* d = new TreeNode(1);
    TreeNode* e = new TreeNode(8);
    TreeNode* f = new TreeNode(12);
    TreeNode* g = new TreeNode(20);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;

    vector<int> v;

    // Store BST elements in sorted order
    inorder(a, v);

    cout << "Inorder values: ";
    for(int x : v){
        cout << x << " ";
    }
    cout << endl;

    // Convert BST to Min Heap
    int idx = 0;
    preorderFill(a, v, idx);

    cout << "Preorder of Min Heap: ";
    preorderPrint(a);
    cout << endl;

    return 0;
}