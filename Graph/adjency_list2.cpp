#include<iostream>
#include<vector>
#include<list>

using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::pair;


// weighted and directed graph
vector<list<pair<int,int>>> graph; // {neighbor, weight}

int v;

void add_edge(int src, int dest, int wt, bool bi_dir = false) {
    graph[src].push_back({dest, wt});

    if (bi_dir) {
        graph[dest].push_back({src, wt});
    }
}

int main() {
    v = 5;
    graph.resize(v);

    add_edge(0, 1, 5); // 0 -> 1 (weight 5)
    add_edge(0, 2, 3); // 0 -> 2 (weight 3)
    add_edge(1, 3, 2); // 1 -> 3 (weight 2)
    add_edge(2, 4, 4); // 2 -> 4 (weight 4)

    for (int i = 0; i < v; i++) {
        cout << i << " -> ";

        for (auto neighbor : graph[i]) {
            cout << "(" << neighbor.first
                 << "," << neighbor.second << ") ";
        }

        cout << endl;
    }

    return 0;
}