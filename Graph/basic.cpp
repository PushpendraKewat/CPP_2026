#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main() {
    int n = 4;

    vector<vector<int>> graph(n);

    graph[0].push_back(1);
    graph[0].push_back(2);

    graph[1].push_back(0);
    graph[1].push_back(3);

    graph[2].push_back(0);
    graph[2].push_back(3);

    graph[3].push_back(1);
    graph[3].push_back(2);

    for(int i = 0; i < n; i++) {
        cout << i << " -> ";
        for(int neighbor : graph[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }

    return 0;
}