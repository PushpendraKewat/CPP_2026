#include<iostream>
#include<vector>
#include<queue>
#include<list>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::queue;
using std::list;

vector<list<int>> graph;

void add_edge(int a, int b) {
    graph[a].push_back(b);
}

void topoBFS(int v) {
    vector<int> indegree(v, 0);

    for(int i = 0; i < v; i++) {
        for(auto neighbour : graph[i]) {
            indegree[neighbour]++;
        }
    }

    queue<int> q;

    for(int i = 0; i < v; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topo;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        topo.push_back(node);

        for(auto neighbour : graph[node]) {
            indegree[neighbour]--;

            if(indegree[neighbour] == 0) {
                q.push(neighbour);
            }
        }
    }

    if(topo.size() != v) {
        cout << "Cycle exists" << endl;
        return;
    }

    cout << "Topological Order: ";
    for(int node : topo) {
        cout << node << " ";
    }
    cout << endl;
}

int main() {
    int v, e;

    cout << "Enter vertices and edges: ";
    cin >> v >> e;

    graph.resize(v);
    cout<<"Enter src & des :";
    while(e--) {
        int src, dest;
        cin >> src >> dest;

        add_edge(src, dest);
    }

    topoBFS(v);

    return 0;
}