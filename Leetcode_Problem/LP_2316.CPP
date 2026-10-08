
// 2316. Count Unreachable Pairs of Nodes
// in an Undirected Graph
class Solution {
public:
    vector<int> parent;
    vector<int> sz;

    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void union_set(int a, int b){
        a = find(a);
        b = find(b);

        if(a == b) return;

        if(sz[a] < sz[b]){
            parent[a] = b;
            sz[b] += sz[a];
        }
        else{
            parent[b] = a;
            sz[a] += sz[b];
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        sz.resize(n, 1);

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }

        for(auto& e : edges){
            union_set(e[0], e[1]);
        }

        vector<long long> cc;

        for(int i = 0; i < n; i++){
            if(find(i) == i){
                cc.push_back(sz[i]);
            }
        }

        int m = cc.size();

        vector<long long> suffix(m + 1, 0);

        for(int i = m - 1; i >= 0; i--){
            suffix[i] = suffix[i + 1] + cc[i];
        }

        long long ans = 0;

        for(int i = 0; i < m; i++){
            ans += cc[i] * suffix[i + 1];
        }

        return ans;
    }
};