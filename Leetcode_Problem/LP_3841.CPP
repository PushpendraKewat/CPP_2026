// 3841. Palindromic Path Queries in a Tree
class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(n, vector<int>(LOG));
        vector<int> tin(n), tout(n), depth(n);
        vector<int> basePrefix(n);
        vector<int> mask(n);

        for (int i = 0; i < n; i++) {
            mask[i] = 1 << (s[i] - 'a');
        }

        int timer = 0;

        vector<tuple<int, int, int>> st;
        st.push_back({0, 0, 0});

        while (!st.empty()) {
            auto [u, p, state] = st.back();
            st.pop_back();

            if (state == 0) {
                tin[u] = timer++;

                up[u][0] = p;

                for (int j = 1; j < LOG; j++) {
                    up[u][j] = up[up[u][j - 1]][j - 1];
                }

                basePrefix[u] = (u == 0 ? 0 : basePrefix[p]) ^ mask[u];

                st.push_back({u, p, 1});

                for (int v : adj[u]) {
                    if (v == p) continue;

                    depth[v] = depth[u] + 1;
                    st.push_back({v, u, 0});
                }
            } else {
                tout[u] = timer - 1;
            }
        }

        vector<int> bit(n + 2, 0);

        auto updateBIT = [&](int idx, int val) {
            for (; idx <= n + 1; idx += idx & -idx) {
                bit[idx] ^= val;
            }
        };

        auto queryBIT = [&](int idx) {
            int res = 0;

            for (; idx > 0; idx -= idx & -idx) {
                res ^= bit[idx];
            }

            return res;
        };

        auto updateSubtree = [&](int u, int val) {
            updateBIT(tin[u] + 1, val);
            updateBIT(tout[u] + 2, val);
        };

        auto getPrefix = [&](int u) {
            return basePrefix[u] ^ queryBIT(tin[u] + 1);
        };

        auto getLCA = [&](int u, int v) {
            if (depth[u] < depth[v]) {
                swap(u, v);
            }

            int diff = depth[u] - depth[v];

            for (int j = 0; j < LOG; j++) {
                if (diff & (1 << j)) {
                    u = up[u][j];
                }
            }

            if (u == v) return u;

            for (int j = LOG - 1; j >= 0; j--) {
                if (up[u][j] != up[v][j]) {
                    u = up[u][j];
                    v = up[v][j];
                }
            }

            return up[u][0];
        };

        vector<bool> ans;

        for (string& q : queries) {
            string type;
            int u, v;

            stringstream ss(q);
            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                int newMask = 1 << (c - 'a');
                int delta = mask[u] ^ newMask;

                updateSubtree(u, delta);
                mask[u] = newMask;
            } else {
                ss >> v;

                int lca = getLCA(u, v);

                int pathMask = getPrefix(u)
                             ^ getPrefix(v)
                             ^ mask[lca];

                ans.push_back((pathMask & (pathMask - 1)) == 0);
            }
        }

        return ans;
    }
};