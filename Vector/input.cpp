#include<iostream>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main(){
    int n;
    cout << "Enter size of vector: ";
    cin >> n;

    vector<int> v(n);

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    cout << "Elements in vector: ";
    for(int x : v){
        cout << x << " ";
    }

    return 0;
}
