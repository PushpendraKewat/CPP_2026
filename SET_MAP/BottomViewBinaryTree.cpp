#include <iostream>
#include <queue>
#include <map>

using std::cout;
using std::endl;
using std::queue;
using std::map;
using std::pair;

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

void TopView(TreeNode* root) {
    if (root == nullptr) return;

    map<int, int> m; // horizontal distance -> node value
    queue<pair<TreeNode*, int>> q;

    q.push({root, 0});

    while (!q.empty()) {
        TreeNode* temp = q.front().first;
        int hd = q.front().second;
        q.pop();

        if (m.find(hd) == m.end()) {
            m[hd] = temp->val;
        }

        if (temp->left) {
            q.push({temp->left, hd - 1});
        }

        if (temp->right) {
            q.push({temp->right, hd + 1});
        }
    }

    for (auto x : m) {
        cout << x.second << " ";
    }
    cout << endl;
}

void BottomView(TreeNode* root) {
    if (root == nullptr) return;

    map<int, int> m; // horizontal distance -> node value
    queue<pair<TreeNode*, int>> q;

    q.push({root, 0});

    while (!q.empty()) {
        TreeNode* temp = q.front().first;
        int hd = q.front().second;
        q.pop();

        m[hd] = temp->val; // overwrite

        if (temp->left) {
            q.push({temp->left, hd - 1});
        }

        if (temp->right) {
            q.push({temp->right, hd + 1});
        }
    }

    for (auto x : m) {
        cout << x.second << " ";
    }
    cout << endl;
}

int main() {
    TreeNode* a = new TreeNode(1);
    TreeNode* b = new TreeNode(2);
    TreeNode* c = new TreeNode(3);
    TreeNode* d = new TreeNode(4);
    TreeNode* e = new TreeNode(5);
    TreeNode* f = new TreeNode(6);
    TreeNode* g = new TreeNode(7);
    TreeNode* h = new TreeNode(8);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->right = f;
    e->left = g;
    e->right = h;

    cout << "Level Order: ";
    levelOrder(a);

    cout << "Top View: ";
    TopView(a);

    cout << "Bottom View: ";
    BottomView(a);

    return 0;
}