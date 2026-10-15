#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<cmath>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::priority_queue;
using std::pair;
using std::greater;
using std::abs;

struct Edge {
    int u, v, wt;
};

vector<Edge> edges;
vector<vector<pair<int,int>>> graph;
vector<pair<int,int>> coordinates;

void add_edge(int u, int v, int wt) {
    edges.push_back({u, v, wt});
    graph[u].push_back({v, wt});
}

int heuristic(int u, int goal) {
    return abs(coordinates[u].first -
               coordinates[goal].first)
         + abs(coordinates[u].second -
               coordinates[goal].second);
}

void a_star(int src, int goal, int n) {
    vector<int> dist(n, INT_MAX);

    // {f, vertex}
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    dist[src] = 0;

    pq.push({heuristic(src, goal), src});

    while(!pq.empty()) {
        int f = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(f != dist[u] + heuristic(u, goal)) {
            continue;
        }

        if(u == goal) {
            break;
        }

        for(const pair<int,int>& edge : graph[u]) {
            int v = edge.first;
            int wt = edge.second;

            if(dist[u] != INT_MAX &&
               dist[u] + wt < dist[v]) {

                dist[v] = dist[u] + wt;

                int newF = dist[v] + heuristic(v, goal);

                pq.push({newF, v});
            }
        }
    }

    if(dist[goal] == INT_MAX) {
        cout << "Goal is unreachable\n";
    }
    else {
        cout << "Shortest distance from "
             << src << " to " << goal
             << " = " << dist[goal] << endl;
    }
}

int main() {
    int n, m;

    cout << "Enter n and m: ";
    cin >> n >> m;

    graph.resize(n);
    coordinates.resize(n);

    cout << "Enter coordinates (x y) for each vertex:\n";

    for(int i = 0; i < n; i++) {
        cin >> coordinates[i].first
            >> coordinates[i].second;
    }

    cout << "Enter directed edges (u v weight):\n";

    for(int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;

        add_edge(u, v, wt);
    }

    int src, goal;

    cout << "Enter source and goal: ";
    cin >> src >> goal;

    if(src < 0 || src >= n ||
       goal < 0 || goal >= n) {
        cout << "Invalid source or goal vertex\n";
        return 0;
    }

    a_star(src, goal, n);

    return 0;
}