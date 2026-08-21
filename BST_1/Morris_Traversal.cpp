#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() {
        this->val = val;
        left = right = nullptr;
    }
};

vector<int> inOrder(TreeNode* root) {
    vector<int> res;
    TreeNode* curr = root;

    while (curr != nullptr) {
        if (curr->left == nullptr) {
          
            // If no left child, visit this node 
            // and go right
            res.push_back(curr->data);
            curr = curr->right;
        }
        else {
          
            // Find the inorder predecessor of curr
            TreeNode* prev = curr->left;
            while (prev->right != nullptr &&
                                 prev->right != curr) {
                prev = prev->right;
            }

            // Make curr the right child of its 
            // inorder predecessor
            if (prev->right == nullptr) {
                prev->right = curr;
                curr = curr->left;
            } 
            else {
              
                // Revert the changes made in 
                // the tree structure
                prev->right = nullptr;
                res.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return res;
}


int main() {
  
    // Representation of input binary tree:
    //           1
    //          / \
    //         2   3
    //        / \  
    //       4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<int> res = inOrder(root);
  
     for (int x : res) {
        cout << x << " ";
    }
    
    return 0;
}