#include<iostream>
#include<vector>
#include<algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;

int find(int x, vector<int>& parent) {
    if(parent[x] == x) return x;

    return parent[x] = find(parent[x], parent); // path compression
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

struct Edge {
    int src;
    int dest;
    int wt;
};

bool cmp(Edge e1, Edge e2) {
    return e1.wt < e2.wt;
}

// Kruskal's Algorithm
void krushkal(int n, vector<Edge>& edges) {
    vector<int> parent(n);
    vector<int> rank(n, 0);

    for(int i = 0; i < n; i++) {
        parent[i] = i;
    }

    // Sort edges by increasing weight
    sort(edges.begin(), edges.end(), cmp);

    int mstWeight = 0;
    int count = 0;

    for(auto e : edges) {
        int u = e.src;
        int v = e.dest;
        int wt = e.wt;

        // Check if adding this edge creates a cycle
        if(find(u, parent) != find(v, parent)) {
            union_set(u, v, parent, rank);

            cout << u << " - " << v << " : " << wt << endl;

            mstWeight += wt;
            count++;

            if(count == n - 1) break;
        }
    }

    if(count == n - 1) {
        cout << "MST Weight: " << mstWeight << endl;
    }
    else {
        cout << "MST does not exist because the graph is disconnected." << endl;
    }
}

int main() {
    int n, m;

    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<Edge> edges(m);

    cout << "Enter source, destination and weight of each edge:\n";

    for(int i = 0; i < m; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].wt;
    }

    krushkal(n, edges);

    return 0;
}