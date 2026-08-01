#include <iostream>

using std::cout;
using std::endl;

class Queue {
public:
    int f;
    int b;
    int arr[5];

    Queue() {
        f = 0;
        b = 0;
    }

    void push(int val) {
        if (b == 5) {
            cout << "Queue is full\n";
            return;
        }

        arr[b] = val;
        b++;
    }

    void pop() {
        if (f == b) {
            cout << "Queue is empty\n";
            return;
        }

        f++;
    }

    int Front() {
        if (size() == 0) return -1;
        return arr[f];
    }

    int Back() {
        if (size() == 0) return -1;
        return arr[b - 1];
    }

    int size() {
        return b - f;
    }

    bool empty() {
        return f == b;
    }

    void display() {
        for (int i = f; i < b; i++) {
            cout << arr[i] << " ";
        }
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
    q.push(60);   // Queue is full

    q.display();

    cout << q.Front() << endl;
    cout << q.Back() << endl;

    q.pop();
    q.display();
}