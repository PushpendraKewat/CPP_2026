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
    if(root==nullptr) return;

    inorder(root->right,v);
    v.push_back(root->val);
    inorder(root->left,v);
}

void print(vector<int>& v){
    for(int i =0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void preorder(TreeNode* root, vector<int>& v, int& i ){
    if(root==nullptr) return;

    root->val = v[i++];
    preorder(root->left,v,i);
    preorder(root->right,v,i);
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

   vector<int> v; // reverse order
   inorder(a,v);
   print(v);

   int i = 0;
   preorder(a,v,i);
   preorderPrint(a);
   cout<<endl;
    return 0;
}