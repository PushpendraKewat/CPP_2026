// method 2 dfs
class Solution {
public:
    void dfs(vector<vector<int>>& rooms, int curr, vector<bool>& visited) {
        visited[curr] = true;

        for (int key : rooms[curr]) {
            if (!visited[key]) {
                dfs(rooms, key, visited);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        vector<bool> visited(n, false);

        dfs(rooms, 0, visited);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                return false;
            }
        }

        return true;
    }
};

// METHOD 1 bfs
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> visited;
        queue<int> q;

        q.push(0);
        visited.insert(0);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int key : rooms[curr]) {
                if (!visited.count(key)) {
                    visited.insert(key);
                    q.push(key);
                }
            }
        }

        return visited.size() == rooms.size();
    }
};