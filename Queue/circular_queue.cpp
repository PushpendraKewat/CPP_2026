#include <iostream>

using namespace std;

class CircularQueue {
public:
    int f;
    int b;
    int s;
    int arr[5];

    CircularQueue() {
        f = 0;
        b = 0;
        s = 0;
    }

    void push(int val) {
        if (s == 5) {
            cout << "Queue is full\n";
            return;
        }

        arr[b] = val;
        b = (b + 1) % 5;
        s++;
    }

    void pop() {
        if (s == 0) {
            cout << "Queue is empty\n";
            return;
        }

        f = (f + 1) % 5;
        s--;
    }

    int Front() {
        if (s == 0) return -1;
        return arr[f];
    }

    int Back() {
        if (s == 0) return -1;
        return arr[(b - 1 + 5) % 5];
    }

    int size() {
        return s;
    }

    bool empty() {
        return s == 0;
    }

    void display() {
        if (s == 0) {
            cout << "Queue is empty\n";
            return;
        }

        int i = f;
        for (int cnt = 0; cnt < s; cnt++) {
            cout << arr[i] << " ";
            i = (i + 1) % 5;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    q.display();

    q.pop();
    q.pop();

    q.display();

    q.push(60);
    q.push(70);

    q.display();

    cout << "Front = " << q.Front() << endl;
    cout << "Back = " << q.Back() << endl;

    return 0;
}