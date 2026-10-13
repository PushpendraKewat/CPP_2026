
#include<iostream>
#include<vector>
#include<climits>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Edge {
    int u, v, wt;
};

vector<Edge> edges;

void add_edge(int u, int v, int wt) {
    edges.push_back({u, v, wt});
}

void bellman_ford(int src, int n) {
    vector<int> dist(n, INT_MAX);

    dist[src] = 0;

    // Relax all edges n - 1 times
    for(int i = 1; i < n; i++) {
        bool updated = false;

        for(const Edge& edge : edges) {
            int u = edge.u;
            int v = edge.v;
            int wt = edge.wt;

            if(dist[u] != INT_MAX &&
               dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
                updated = true;
            }
        }

        if(!updated) {
            break;
        }
    }

    // Check for a negative-weight cycle
    for(const Edge& edge : edges) {
        int u = edge.u;
        int v = edge.v;
        int wt = edge.wt;

        if(dist[u] != INT_MAX &&
           dist[u] + wt < dist[v]) {
            cout << "Negative weight cycle detected\n";
            return;
        }
    }

    cout << "\nShortest distances from source "
         << src << ":\n";

    for(int i = 0; i < n; i++) {
        cout << src << " -> " << i << " = ";

        if(dist[i] == INT_MAX) {
            cout << "Unreachable";
        }
        else {
            cout << dist[i];
        }

        cout << endl;
    }
}

int main() {
    int n, m;

    cout << "Enter n and m: ";
    cin >> n >> m;

    cout << "Enter directed edges (u v weight):\n";

    while(m--) {
        int u, v, wt;
        cin >> u >> v >> wt;

        add_edge(u, v, wt);
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    if(src < 0 || src >= n) {
        cout << "Invalid source vertex\n";
        return 0;
    }

    bellman_ford(src, n);

    return 0;
}
