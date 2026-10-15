// 785. Is Graph Bipartite?
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
        // Color array to store the color assigned to each node (-1 means uncolored)
        vector<int> color(n, -1);

        // Iterate through each node to handle disconnected components
        for (int i = 0; i < n; i++) {
            // If the node is already colored, it has been visited
            if (color[i] != -1) continue;

            // Start BFS for each component from an unvisited node
            queue<int> q;
            q.push(i);
            color[i] = 0;

            while (!q.empty()) {
                int curr = q.front();
                q.pop();

                // Check all neighbors
                for (auto neighbor : graph[curr]) {
                    // If the neighbor is uncolored, color it with opposite color
                    if (color[neighbor] == -1) {
                        color[neighbor] = 1 - color[curr];
                        q.push(neighbor);
                    }
                    // If the neighbor has the same color, the graph is not bipartite
                    else if (color[neighbor] == color[curr]) {
                        return false;
                    }
                }
            }
        }

        // If all components are bipartite, return true
        return true;
    }
};
