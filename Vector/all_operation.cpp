#include <iostream>
#include <vector>
#include <algorithm>   // sort, reverse, find
using namespace std;

// function to print vector (const reference)
void printVector(const vector<int>& v){
    for(int x : v){
        cout << x << " ";
    }
    cout << endl;
}

int main(){

    // 1️⃣ Declaration & Initialization
    vector<int> v;                 // empty vector
    vector<int> v1 = {1,2,3,4};     // initializer list
    vector<int> v2(5);              // size 5, all 0
    vector<int> v3(5, 10);           // size 5, all 10

    cout << "v: ";
    printVector(v);
    
    cout << "v1: ";
    printVector(v1);

    cout << "v2: ";
    printVector(v2);

    cout << "v3: ";
    printVector(v3);

    // 2️⃣ push_back & emplace_back
    v.push_back(10);
    v.push_back(20);
    v.emplace_back(30);

    cout << "\nv after push_back: ";
    printVector(v);

    // 3️⃣ Size, Capacity, Empty
    cout << "Size: " << v.size() << endl;
    cout << "Capacity: " << v.capacity() << endl;
    cout << "Is empty? " << v.empty() << endl;

    // 4️⃣ Access elements
    cout << "First element: " << v.front() << endl;
    cout << "Last element: " << v.back() << endl;
    cout << "Element at index 1: " << v[1] << endl;

    // 5️⃣ Insert elements
    v.insert(v.begin() + 1, 99);    // insert at index 1
    cout << "\nAfter insert: ";
    printVector(v);

    // 6️⃣ Erase elements
    v.erase(v.begin() + 1);         // erase index 1
    cout << "After erase: ";
    printVector(v);

    // 7️⃣ pop_back
    v.pop_back();
    cout << "After pop_back: ";
    printVector(v);

    // 8️⃣ Resize & Reserve
    v.resize(5, 7);                 // resize to 5, fill new with 7
    cout << "\nAfter resize: ";
    printVector(v);

    v.reserve(20);                  // reserve capacity
    cout << "Capacity after reserve: " << v.capacity() << endl;

    // 9️⃣ Sorting & Reversing
    sort(v.begin(), v.end());
    cout << "\nAfter sort: ";
    printVector(v);

    reverse(v.begin(), v.end());
    cout << "After reverse: ";
    printVector(v);

    // 🔟 Searching
    int x = 7;
    if(find(v.begin(), v.end(), x) != v.end()){
        cout << x << " found in vector" << endl;
    } else {
        cout << x << " not found in vector" << endl;
    }

    // 1️⃣1️⃣ Clear vector
    v.clear();
    cout << "\nAfter clear, size: " << v.size() << endl;

    // 1️⃣2️⃣ Pointer access (connection to array)
    vector<int> vp = {5,6,7};
    int* p = vp.data();
    cout << "Using pointer: " << p[0] << " " << p[1] << " " << p[2] << endl;

    // 1️⃣3️⃣ 2D Vector
    vector<vector<int>> mat(2, vector<int>(3, 1));
    cout << "\n2D Vector:\n";
    for(int i = 0; i < mat.size(); i++){
        for(int j = 0; j < mat[i].size(); j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
