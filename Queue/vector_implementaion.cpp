#include <iostream>
#include <vector>

using namespace std;

class Queue {
private:
    vector<int> v;
    int front;

public:
    Queue() {
        front = 0;
    }

    void push(int val) {
        v.push_back(val);
    }

    void pop() {
        if (empty()) {
            cout << "Queue is empty\n";
            return;
        }
        front++;
    }

    int Front() {
        if (empty()) return -1;
        return v[front];
    }

    int Back() {
        if (empty()) return -1;
        return v.back();
    }

    int size() {
        return v.size() - front;
    }

    bool empty() {
        return front == v.size();
    }

    void display() {
        for (int i = front; i < v.size(); i++)
            cout << v[i] << " ";
        cout << endl;
    }
};

int main() {
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    q.display();

    q.pop();
    q.pop();

    q.display();

    cout << "Front: " << q.Front() << endl;
    cout << "Back: " << q.Back() << endl;
    cout << "Size: " << q.size() << endl;
}