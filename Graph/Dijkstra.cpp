
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

void dijkstra(int src, int n) {
    vector<int> dist(n, INT_MAX);
    vector<bool> vis(n, false);

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()) {
        int currDist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(vis[node]) {
            continue;
        }

        vis[node] = true;

        for(const pair<int,int>& edge : g[node]) {
            int nbr = edge.first;
            int wt = edge.second;

            if(!vis[nbr] && currDist + wt < dist[nbr]) {
                dist[nbr] = currDist + wt;
                pq.push({dist[nbr], nbr});
            }
        }
    }

    cout << "\nShortest distances from source " << src << ":\n";

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

    g.resize(n);

    cout << "Enter edges (u v weight):\n";

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

    dijkstra(src, n);

    return 0;
}
