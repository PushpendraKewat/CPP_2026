#include<iostream>
#include<vector>
#include<algorithm>

using std::cout;
using std::endl;
using std::vector;

class MaxHeap{
public:
    vector<int> v;

    MaxHeap(){
        v.push_back(-1); // dummy element
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

        while(i > 1 && v[i] > v[i / 2]){
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
            int largest = i;

            if(l < v.size() && v[l] > v[largest]){
                largest = l;
            }

            if(r < v.size() && v[r] > v[largest]){
                largest = r;
            }

            if(largest == i){
                break;
            }

            std::swap(v[i], v[largest]);
            i = largest;
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
    MaxHeap pq;

    pq.push(10);
    pq.push(20);
    pq.push(30);
    pq.push(5);
    pq.push(15);

    cout << "Top: " << pq.top() << endl; // 30

    pq.pop();

    cout << "Top after pop: " << pq.top() << endl; // 20

    return 0;
}