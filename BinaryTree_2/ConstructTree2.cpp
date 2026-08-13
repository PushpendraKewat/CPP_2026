#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using std::cout;
using std::endl;
using std::vector;
using std::queue;

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

TreeNode* construct(vector<int>& v) {
    if (v.empty() || v[0] == INT_MIN) return nullptr;

    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(v[0]);
    q.push(root);

    int i = 1;

    while (!q.empty() && i < v.size()) {
        TreeNode* curr = q.front();
        q.pop();

        if (i < v.size() && v[i] != INT_MIN) {
            curr->left = new TreeNode(v[i]);
            q.push(curr->left);
        }
        i++;

        if (i < v.size() && v[i] != INT_MIN) {
            curr->right = new TreeNode(v[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

void levelOrder(TreeNode* root) {
    if (root == nullptr) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();

        cout << temp->val << " ";

        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }

    cout << endl;
}

int main() {
    // INT_MIN represents nullptr
    vector<int> v = {
        1, 2, 3, 4, 5, INT_MIN, 6,
        INT_MIN, INT_MIN, 7, 8, 9, INT_MIN
    };

    TreeNode* root = construct(v);

    cout << "Level Order Traversal: ";
    levelOrder(root);

    return 0;
}