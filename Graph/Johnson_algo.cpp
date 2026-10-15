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

const long long INF = LLONG_MAX / 4;

struct Edge {
    int u, v, wt;
};

vector<Edge> edges;
vector<vector<pair<int,int>>> graph;

void add_edge(int u, int v, int wt) {
    edges.push_back({u, v, wt});
    graph[u].push_back({v, wt});
}

bool bellman_ford(int n, vector<long long>& h) {
    // Equivalent to adding a super-source
    // with zero-weight edges to every vertex.
    h.assign(n, 0);

    for(int i = 0; i < n; i++) {
        bool updated = false;

        for(const Edge& edge : edges) {
            int u = edge.u;
            int v = edge.v;
            int wt = edge.wt;

            if(h[u] + wt < h[v]) {
                h[v] = h[u] + wt;
                updated = true;
            }
        }

        if(!updated) {
            return true;
        }

        // An update on the nth pass means a negative cycle.
        if(i == n - 1) {
            return false;
        }
    }

    return true;
}

void dijkstra(int src, int n,
              vector<long long>& h,
              vector<long long>& dist) {

    dist.assign(n, INF);

    priority_queue<
        pair<long long,int>,
        vector<pair<long long,int>>,
        greater<pair<long long,int>>
    > pq;

    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()) {
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(d != dist[u]) {
            continue;
        }

        for(const pair<int,int>& edge : graph[u]) {
            int v = edge.first;
            int wt = edge.second;

            // Reweight the edge.
            long long newWt = wt + h[u] - h[v];

            if(d + newWt < dist[v]) {
                dist[v] = d + newWt;
                pq.push({dist[v], v});
            }
        }
    }

    // Convert distances back to original edge weights.
    for(int v = 0; v < n; v++) {
        if(dist[v] != INF) {
            dist[v] = dist[v] - h[src] + h[v];
        }
    }
}

void johnson(int n) {
    vector<long long> h;

    if(!bellman_ford(n, h)) {
        cout << "Graph contains a negative-weight cycle\n";
        return;
    }

    vector<vector<long long>> dist(
        n, vector<long long>(n, INF)
    );

    for(int src = 0; src < n; src++) {
        dijkstra(src, n, h, dist[src]);
    }

    cout << "\nAll-pairs shortest distance matrix:\n";

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(dist[i][j] == INF) {
                cout << "INF ";
            }
            else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int n, m;

    cout << "Enter n and m: ";
    cin >> n >> m;

    graph.resize(n);

    cout << "Enter directed edges (u v weight):\n";

    for(int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;

        if(u < 0 || u >= n || v < 0 || v >= n) {
            cout << "Invalid vertex\n";
            return 0;
        }

        add_edge(u, v, wt);
    }

    johnson(n);

    return 0;
}