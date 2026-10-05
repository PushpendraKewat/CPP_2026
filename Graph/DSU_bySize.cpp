#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;
using std::swap;

class DSU {
public:
    vector<int> parent;
    vector<int> size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if(parent[x] == x) return x;

        return find(parent[x]);
    }

    void union_set(int a, int b) {
        int parentA = find(a);
        int parentB = find(b);

        if(parentA == parentB) return;

        if(size[parentB] >= size[parentA]) {
            swap(parentB, parentA);
        }

        parent[parentB] = parentA;
        size[parentA] += size[parentB];
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