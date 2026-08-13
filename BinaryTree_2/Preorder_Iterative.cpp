#include <iostream>
#include <stack>

using std::cout;
using std::endl;
using std::stack;

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

void preorderIterative(TreeNode* root) {
    if (root == nullptr) return;

    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        TreeNode* temp = st.top();
        st.pop();

        cout << temp->val << " ";

        if (temp->right) st.push(temp->right);
        if (temp->left) st.push(temp->left);
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

    a->left = b;
    a->right = c;

    b->left = d;
    b->right = e;

    c->left = f;
    c->right = g;

    preorderIterative(a);

    return 0;
}