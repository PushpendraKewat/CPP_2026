#include<iostream>
#include<vector>
#include<climits>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Edge {
    int u, v, wt;
};

vector<Edge> edges;

void add_edge(int u, int v, int wt) {
    edges.push_back({u, v, wt});
}

void floyd_warshall(vector<vector<int>>& dist, int n) {
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {

                if(dist[i][k] != INT_MAX &&
                   dist[k][j] != INT_MAX) {

                    if(dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }
}

int main() {
    int n, m;

    cout << "Enter vertex and edge: ";
    cin >> n >> m;

    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

    for(int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }

    cout << "Enter directed edges (u v weight):\n";

    for(int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;

        add_edge(u, v, wt);
        dist[u][v] = wt;
    }

    floyd_warshall(dist, n);

    cout << "\nShortest distance matrix:\n";

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(dist[i][j] == INT_MAX) {
                cout << "INF ";
            }
            else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}