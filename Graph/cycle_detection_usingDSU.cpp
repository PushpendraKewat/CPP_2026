#include<iostream>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int find(int x, vector<int>& parent) {
    if(parent[x] == x) return x;

    return parent[x] = find(parent[x], parent);
}

void union_set(int a, int b, vector<int>& parent, vector<int>& rank) {
    a = find(a, parent);
    b = find(b, parent);

    if(a == b) return;

    if(rank[a] < rank[b]) {
        parent[a] = b;
    }
    else if(rank[a] > rank[b]) {
        parent[b] = a;
    }
    else {
        parent[b] = a;
        rank[a]++;
    }
}

int main() {
    int vertices, edges;

    cout << "Enter number of vertices and edges : ";
    cin >> vertices >> edges;

    vector<int> parent(vertices);
    vector<int> rank(vertices, 0);

    for(int i = 0; i < vertices; i++) {
        parent[i] = i;
    }

    bool cycle = false;

    cout << "Enter edges (u v):\n";

    for(int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;

        if(find(u, parent) == find(v, parent)) {
            cycle = true;
            break;
        }

        union_set(u, v, parent, rank);
    }

    if(cycle)
        cout << "Cycle Exists\n";
    else
        cout << "No Cycle\n";

    return 0;
}