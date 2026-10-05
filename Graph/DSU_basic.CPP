#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;

class DSU {
public:
    vector<int> parent;

    DSU(int n) {
        parent.resize(n);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if(parent[x] == x) return x;

        return find(parent[x]);
    }

    void union_set(int a, int b) {
        a = find(a);
        b = find(b);

        if(a != b) {
            parent[b] = a;
        }
    }
};

int main() {
    DSU dsu(5);

    dsu.union_set(0, 1);
    dsu.union_set(1, 2);

    cout << dsu.find(0) << endl;
    cout << dsu.find(1) << endl;
    cout << dsu.find(2) << endl;
    cout << dsu.find(3) << endl;

    return 0;
}