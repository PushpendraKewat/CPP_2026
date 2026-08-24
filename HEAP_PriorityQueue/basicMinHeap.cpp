#include <iostream>
#include <queue>
#include <vector>

using std::cout;
using std::endl;
using std::priority_queue;
using std::vector;
using std::greater;

int main() {
    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(10);
    pq.push(30);
    pq.push(20);

    cout << pq.top() << endl; // 10

    return 0;
}