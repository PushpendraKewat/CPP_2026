#include<iostream>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main(){
    int n, m;

    cout << "Enter rows : ";
    cin >> n;

    cout << "Enter columns : ";
    cin >> m;

    vector<vector<int>> v(n, vector<int>(m));

    cout << "Enter roll numbers / marks :\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> v[i][j];
        }
    }

    // display
    cout << "Roll number and marks of students:\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
