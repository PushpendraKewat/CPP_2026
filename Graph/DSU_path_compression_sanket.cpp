#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;

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

int main() {
    int n = 5;

    vector<int> parent(n);
    vector<int> rank(n, 0);

    for(int i = 0; i < n; i++) {
        parent[i] = i;
    }

    union_set(0, 1, parent, rank);
    union_set(2, 3, parent, rank);
    union_set(0, 2, parent, rank);

    cout << find(0, parent) << endl;
    cout << find(1, parent) << endl;
    cout << find(2, parent) << endl;
    cout << find(3, parent) << endl;
    cout << find(4, parent) << endl;

    return 0;
}