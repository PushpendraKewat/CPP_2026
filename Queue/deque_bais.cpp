#include <iostream>
#include <deque>

using namespace std;

int main() {
    deque<int> dq;

    dq.push_back(20);
    dq.push_back(30);

    dq.push_front(10);
    dq.push_front(5);

    cout << "Front: " << dq.front() << endl;
    cout << "Back : " << dq.back() << endl;

    while (!dq.empty()) {
        cout << dq.front() << " ";
        dq.pop_front();
    }
}