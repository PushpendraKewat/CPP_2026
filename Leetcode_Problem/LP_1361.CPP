class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> indegree(n, 0);

        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) {
                indegree[leftChild[i]]++;
                if (indegree[leftChild[i]] > 1) return false;
            }

            if (rightChild[i] != -1) {
                indegree[rightChild[i]]++;
                if (indegree[rightChild[i]] > 1) return false;
            }
        }

        int root = -1;
        int roots = 0;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                root = i;
                roots++;
            }
        }

        if (roots != 1) return false;

        vector<bool> visited(n, false);
        queue<int> q;
        q.push(root);
        visited[root] = true;

        int count = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            int left = leftChild[node];
            int right = rightChild[node];

            if (left != -1) {
                if (visited[left]) return false;
                visited[left] = true;
                q.push(left);
            }

            if (right != -1) {
                if (visited[right]) return false;
                visited[right] = true;
                q.push(right);
            }
        }

        return count == n;
    }
};