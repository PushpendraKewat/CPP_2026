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

bool isLeaf(TreeNode* root) {
    return root && root->left == nullptr && root->right == nullptr;
}

void leftBoundary(TreeNode* root) {
    TreeNode* curr = root->left;

    while (curr) {
        if (!isLeaf(curr))
            cout << curr->val << " ";

        if (curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
}

void leafNodes(TreeNode* root) {
    if (root == nullptr) return;

    if (isLeaf(root)) {
        cout << root->val << " ";
        return;
    }

    leafNodes(root->left);
    leafNodes(root->right);
}

void rightBoundary(TreeNode* root) {
    vector<int> temp;
    TreeNode* curr = root->right;

    while (curr) {
        if (!isLeaf(curr))
            temp.push_back(curr->val);

        if (curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }

    for (int i = temp.size() - 1; i >= 0; i--) {
        cout << temp[i] << " ";
    }
}

void boundaryTraversal(TreeNode* root) {
    if (root == nullptr) return;

    if (!isLeaf(root))
        cout << root->val << " ";

    leftBoundary(root);
    leafNodes(root);
    rightBoundary(root);

    cout << endl;
}

int main() {
    vector<int> v = {
        1,
        2, 3,
        4, 5, 6, INT_MIN,
        INT_MIN, 7, 8, INT_MIN, 9, 10
    };

    TreeNode* root = construct(v);

    cout << "Level Order Traversal: ";
    levelOrder(root);

    cout << "Boundary Traversal: ";
    boundaryTraversal(root);

    return 0;
}