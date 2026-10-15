#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::priority_queue;
using std::pair;
using std::greater;

void prims(int n, vector<vector<pair<int,int>>>& adj) {
    vector<bool> vis(n, false);

    // {weight, vertex}
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    pq.push({0, 0});

    int mstWeight = 0;
    int count = 0;

    while(!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        int wt = top.first;
        int u = top.second;

        if(vis[u]) continue;

        vis[u] = true;
        mstWeight += wt;
        count++;

        if(wt != 0) {
            cout << "Vertex: " << u
                 << ", Weight: " << wt << endl;
        }

        for(auto edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if(!vis[v]) {
                pq.push({weight, v});
            }
        }
    }

    if(count == n) {
        cout << "MST Weight: " << mstWeight << endl;
    }
    else {
        cout << "MST does not exist because the graph is disconnected."
             << endl;
    }
}

int main() {
    int n, m;

    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n);

    cout << "Enter source, destination and weight of each edge:\n";

    for(int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    prims(n, adj);

    return 0;
}