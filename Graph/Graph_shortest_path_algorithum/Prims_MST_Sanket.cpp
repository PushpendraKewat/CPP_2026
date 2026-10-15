#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<climits>
#include<functional>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::pair;
using std::priority_queue;
using std::greater;

vector<list<pair<int,int>>> g;

void add_edge(int u, int v, int wt, bool bidir = true) {
    g[u].push_back({v, wt});

    if(bidir) {
        g[v].push_back({u, wt});
    }
}

void prims(int src, int n) {
    vector<bool> vis(n, false);

    // {weight, {current_node, parent}}
    using Edge = pair<int, pair<int,int>>;
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

    pq.push({0, {src, -1}});

    int totalWeight = 0;
    int visitedCount = 0;

    cout << "\nEdges in MST:\n";

    while(!pq.empty()) {
        Edge curr = pq.top();
        pq.pop();

        int wt = curr.first;
        int node = curr.second.first;
        int parent = curr.second.second;

        if(vis[node]) {
            continue;
        }

        vis[node] = true;
        visitedCount++;
        totalWeight += wt;

        if(parent != -1) {
            cout << parent << " - " << node
                 << " : " << wt << endl;
        }

        for(const pair<int,int>& edge : g[node]) {
            int nbr = edge.first;
            int edgeWeight = edge.second;

            if(!vis[nbr]) {
                pq.push({edgeWeight, {nbr, node}});
            }
        }
    }

    if(visitedCount != n) {
        cout << "Graph is disconnected. MST does not exist.\n";
    }
    else {
        cout << "Total MST weight: " << totalWeight << endl;
    }
}

int main() {
    int n, m; // n = vertex, m = edges

    cout << "Enter vertex and edges: ";
    cin >> n >> m;

    g.resize(n);

     // starting edge, ending edge and weight
    cout << "Enter edges (u v weight):\n";

    while(m--) {
       
        int u, v, wt; 
        cin >> u >> v >> wt;

        add_edge(u, v, wt);
    }

    int src;
    cout << "Enter source node: ";
    cin >> src;

    if(src < 0 || src >= n) {
        cout << "Invalid source node\n";
        return 0;
    }

    prims(src, n);

    return 0;
}
