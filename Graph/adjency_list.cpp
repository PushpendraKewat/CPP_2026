#include<iostream>
#include<vector>
#include<list>

using std::cout;
using std::endl;
using std::vector;
using std::list;

//  undirected_unweighted_graph

vector<list<int>> graph;

int v; // number of vertices

void add_edge(int src, int dest, bool bi_dir = true) {
   graph[src].push_back(dest);

    if (bi_dir) {
        graph[dest].push_back(src);
    }
}

int main() {
    v = 5;

    graph.resize(v);

    add_edge(0, 1);
    add_edge(0, 2);
    add_edge(1, 3);
    add_edge(2, 4);

    for (int i = 0; i < v; i++) {
        cout << i << " -> ";

        for (int neighbor : graph[i]) {
            cout << neighbor << " ";
        }

        cout << endl;
    }

    return 0;
}