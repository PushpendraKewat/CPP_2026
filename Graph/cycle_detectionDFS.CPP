#include<iostream>
#include<vector>
#include<list>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::list;

vector<list<int>> graph;
vector<bool> visited;

void add_edge(int src, int dest) {
    graph[src].push_back(dest);
    graph[dest].push_back(src);
}

bool dfs(int curr, int parent) {
    visited[curr] = true;

    for(int neighbour : graph[curr]) {
        if(!visited[neighbour]) {
            if(dfs(neighbour, curr)) {
                return true;
            }
        }
        else if(neighbour != parent) {
            return true;
        }
    }

    return false;
}

int main() {
    int vertices, edges;

    cout << "Enter number of vertices and edges : ";
    cin >> vertices >> edges;

    graph.resize(vertices);
    visited.resize(vertices, false);

    cout << "Enter edges (u v):\n";

    for(int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
    }

    bool cycle = false;

    for(int i = 0; i < vertices; i++) {
        if(!visited[i]) {
            if(dfs(i, -1)) {
                cycle = true;
                break;
            }
        }
    }

    if(cycle)
        cout << "Cycle Exists\n";
    else
        cout << "No Cycle\n";

    return 0;
}