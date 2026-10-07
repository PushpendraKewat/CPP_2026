#include<iostream>
#include<vector>
#include<list>
#include<queue>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::list;
using std::queue;
using std::pair;

vector<list<int>> graph;
vector<bool> visited;

void add_edge(int src, int dest) {
    graph[src].push_back(dest);
    graph[dest].push_back(src);
}

bool bfs(int src) {
    queue<pair<int,int>> q;

    q.push({src, -1});
    visited[src] = true;

    while(!q.empty()) {
        int curr = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(int neighbour : graph[curr]) {

            if(!visited[neighbour]) {
                visited[neighbour] = true;
                q.push({neighbour, curr});
            }
            else if(neighbour != parent) {
                return true;
            }
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
            if(bfs(i)) {
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