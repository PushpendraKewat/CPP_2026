// 3970. Shortest Path With At Most K Consecutive Identical Characters
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        
        vector<vector<pair<int, int>>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        vector<vector<int>> dist(n, vector<int>(k + 1, INT_MAX));

        priority_queue<tuple<int, int, int>,
                       vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>> pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, u, cnt] = pq.top();
            pq.pop();

            if (d != dist[u][cnt]) continue;

            if (u == n - 1) return d;

            for (auto& [v, w] : adj[u]) {
                int nextCnt = (labels[u] == labels[v]) ? cnt + 1 : 1;

                if (nextCnt > k) continue;

                if (d + w < dist[v][nextCnt]) {
                    dist[v][nextCnt] = d + w;
                    pq.push({d + w, v, nextCnt});
                }
            }
        }

        return -1;
    }
};