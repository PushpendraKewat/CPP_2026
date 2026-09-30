#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;

void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited);
        }
    }
}

int countComponents(int n, vector<vector<int>>& graph) {
    vector<bool> visited(n, false);
    int components = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, graph, visited);
            components++;
        }
    }

    return components;
}

int main() {
    int n = 6;

    vector<vector<int>> graph(n);

    graph[0].push_back(1);
    graph[1].push_back(0);

    graph[1].push_back(2);
    graph[2].push_back(1);

    graph[3].push_back(4);
    graph[4].push_back(3);

    cout << countComponents(n, graph) << endl;

    return 0;
}