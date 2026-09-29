class Solution {
public:
    vector<Node*> cloneNodes;

    Node* dfs(Node* node) {
        if (cloneNodes[node->val] != nullptr) {
            return cloneNodes[node->val];
        }

        Node* clone = new Node(node->val);
        cloneNodes[node->val] = clone;

        for (Node* neighbor : node->neighbors) {
            clone->neighbors.push_back(dfs(neighbor));
        }

        return clone;
    }

    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;

        cloneNodes.resize(101, nullptr);

        return dfs(node);
    }
};