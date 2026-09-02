#include<iostream>
#include<vector>
#include<algorithm>

using std::cout;
using std::endl;
using std::vector;

class MinHeap{
public:
    vector<int> v;

    MinHeap(){
        v.push_back(-1); // dummy element for 1-based indexing
    }

    int top(){
        if(v.size() <= 1){
            return -1;
        }
        return v[1];
    }

    void push(int x){
        v.push_back(x);

        int i = v.size() - 1;

        while(i > 1 && v[i] < v[i / 2]){
            std::swap(v[i], v[i / 2]);
            i = i / 2;
        }
    }

    void pop(){
        if(v.size() <= 1){
            return;
        }

        v[1] = v.back();
        v.pop_back();

        int i = 1;

        while(true){
            int l = 2 * i;
            int r = 2 * i + 1;
            int smallest = i;

            if(l < v.size() && v[l] < v[smallest]){
                smallest = l;
            }

            if(r < v.size() && v[r] < v[smallest]){
                smallest = r;
            }

            if(smallest == i){
                break;
            }

            std::swap(v[i], v[smallest]);
            i = smallest;
        }
    }

    int size(){
        return v.size() - 1;
    }

    bool empty(){
        return v.size() == 1;
    }
};

int main(){
    MinHeap pq;

    pq.push(10);
    pq.push(20);
    pq.push(30);
    pq.push(5);
    pq.push(15);

    cout << "Top: " << pq.top() << endl;
    cout << "Size: " << pq.size() << endl;

    pq.pop();

    cout << "After pop" << endl;
    cout << "Top: " << pq.top() << endl;
    cout << "Size: " << pq.size() << endl;

    return 0;
}