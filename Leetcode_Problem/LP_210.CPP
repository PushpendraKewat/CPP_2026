// method 2
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);

        for(auto& pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];

            graph[prereq].push_back(course);
            indegree[course]++;
        }

        queue<int> q;

        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for(int neighbor : graph[node]) {
                indegree[neighbor]--;

                if(indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        if(ans.size() != numCourses) {
            return {};
        }

        return ans;
    }
};


// method 1
class Solution {
public:
    vector<list<int>> graph;
    int v;

    vector<int> topoBFS() {
        vector<int> indegree(v, 0);
        vector<int> topoOrder;

        for (int i = 0; i < v; i++) {
            for (int neighbor : graph[i]) {
                indegree[neighbor]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < v; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int course = q.front();
            q.pop();
            topoOrder.push_back(course);

            for (int neighbor : graph[course]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        if (topoOrder.size() == v) {
            return topoOrder;
        } else {
            return {}; 
        }
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        v = numCourses; 
        graph.resize(v); 

        for (auto pre : prerequisites) {
            int course = pre[0];
            int prerequisite = pre[1];
            graph[prerequisite].push_back(course); 
        }
        return topoBFS();
    }
};
