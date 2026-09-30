#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::list;
using std::unordered_set;

vector<list<int>> graph;
unordered_set<int> visited;

void add_edge(int src, int dest, bool bi_dir = true) {
    graph[src].push_back(dest);

    if (bi_dir) {
        graph[dest].push_back(src);
    }
}

void display() {
    for (int i = 0; i < graph.size(); i++) {
        cout << i << " -> ";

        for (auto neighbour : graph[i]) {
            cout << neighbour << " ";
        }
        cout << endl;
    }
}

void dfs(int node) {
    visited.insert(node);

    for (int neighbour : graph[node]) {
        if (visited.find(neighbour) == visited.end()) {
            dfs(neighbour);
        }
    }
}

int ConnectedComponent() {
    int count = 0;

    for (int i = 0; i < graph.size(); i++) {
        if (visited.find(i) == visited.end()) {
            dfs(i);
            count++;
        }
    }

    return count;
}

int main() {
    int v;
    cout << "Enter no. of vertices: ";
    cin >> v;

    graph.resize(v);

    int e;
    cout << "Enter no. of edges: ";
    cin >> e;

    cout << "Enter edges (src dest):\n";

    while (e--) {
        int s, d;
        cin >> s >> d;
        add_edge(s, d);
    }

    cout << "\nGraph:\n";
    display();

    cout << "\nNumber of Connected Components: "
         << ConnectedComponent() << endl;

    return 0;
}