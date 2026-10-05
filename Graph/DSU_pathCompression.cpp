#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;

class DSU {
public:
    vector<int> parent;
    vector<int> rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if(parent[x] == x) return x;

        return parent[x] = find(parent[x]);
    }

    void union_set(int a, int b) {
        a = find(a);
        b = find(b);

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
};

int main() {
    DSU dsu(5);

    dsu.union_set(0, 1);
    dsu.union_set(2, 3);
    dsu.union_set(0, 2);

    cout << dsu.find(0) << endl;
    cout << dsu.find(1) << endl;
    cout << dsu.find(2) << endl;
    cout << dsu.find(3) << endl;
    cout << dsu.find(4) << endl;

    return 0;
}