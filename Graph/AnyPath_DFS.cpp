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

// Undirected and Unweighted Graph
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

bool dfs(int curr, int end) {
    if (curr == end) {
        return true;
    }

    visited.insert(curr);

    for (auto neighbour : graph[curr]) {
        if (!visited.count(neighbour)) {
            bool result = dfs(neighbour, end);

            if (result) {
                return true;
            }
        }
    }

    return false;
}

bool anyPath(int src, int dest) {
    visited.clear();
    return dfs(src, dest);
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

    int src, dest;
    cout << "\nEnter source and destination: ";
    cin >> src >> dest;

    if (anyPath(src, dest)) {
        cout << "Path Exists" << endl;
    } else {
        cout << "Path Does Not Exist" << endl;
    }

    return 0;
}