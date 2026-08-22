#include <iostream>
#include <queue>

using std::cout;
using std::endl;
using std::priority_queue;

int main() {
    priority_queue<int> pq;

    pq.push(10);
    pq.push(30);
    pq.push(20);

    // by default max heap
    cout << pq.top() << endl; // 30

    return 0;
}