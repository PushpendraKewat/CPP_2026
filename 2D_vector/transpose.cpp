#include<iostream>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main(){
    int n, m;
    cout << "Enter rows and columns of matrix: ";
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));

    cout << "Enter matrix elements:\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    // Display original matrix
    cout << "Original Matrix:\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Transpose matrix
    vector<vector<int>> transpose(m, vector<int>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            transpose[j][i] = arr[i][j];
        }
    }

    // Display transpose matrix
    cout << "Transpose Matrix:\n";
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
