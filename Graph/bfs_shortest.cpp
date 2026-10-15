#include<iostream>
#include<vector>
#include<queue>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::queue;

void bfs_shortest_path(
    vector<vector<int>>& graph,
    int src,
    int n
) {
    vector<int> dist(n, -1);
    vector<int> parent(n, -1);
    queue<int> q;

    dist[src] = 0;
    q.push(src);

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int v : graph[u]) {
            if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    cout << "\nShortest distances from " << src << ":\n";

    for(int i = 0; i < n; i++) {
        cout << src << " -> " << i << " = "
             << dist[i] << endl;
    }
}

int main() {
    int n, m;

    cout << "Enter vertices and edges: ";
    cin >> n >> m;

    vector<vector<int>> graph(n);

    cout << "Enter undirected edges (u v):\n";

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int src;
    cout << "Enter source: ";
    cin >> src;

    if(src < 0 || src >= n) {
        cout << "Invalid source\n";
        return 0;
    }

    bfs_shortest_path(graph, src, n);

    return 0;
}