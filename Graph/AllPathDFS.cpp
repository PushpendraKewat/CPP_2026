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

void printAllPaths(int curr, int dest, vector<int>& path) {
    visited.insert(curr);
    path.push_back(curr);

    if (curr == dest) {
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }
    else {
        for (auto neighbour : graph[curr]) {
            if (!visited.count(neighbour)) {
                printAllPaths(neighbour, dest, path);
            }
        }
    }

    // Backtracking
    path.pop_back();
    visited.erase(curr);
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

    vector<int> path;
    cout << "\nAll Paths:\n";
    printAllPaths(src, dest, path);

    return 0;
}