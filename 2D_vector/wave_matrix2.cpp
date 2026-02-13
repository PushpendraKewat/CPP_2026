#include<iostream>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

void display(vector<vector<int>>& v){
    int m = v.size();
    int n = v[0].size();

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void wave(vector<vector<int>>& v){
    int m = v.size();     // rows
    int n = v[0].size();  // columns

    cout << "Wave print:\n";

    for(int i = 0; i < m; i++){
        if(i % 2 != 0){
            // left → right
            for(int j = 0; j < n; j++){
                cout << v[i][j] << " ";
            }
        }
        else{
            // right → left
            for(int j = n - 1; j >= 0; j--){
                cout << v[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main(){
    int n;
    cout << "Enter the rows/columns of matrix : ";
    cin >> n;

    vector<vector<int>> v(n, vector<int>(n));

    cout << "Enter the elements in matrix:\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> v[i][j];
        }
    }

    cout << "\nOriginal matrix:\n";
    display(v);

    wave(v);

    return 0;
}
