#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main(){
    int n, m;
    cout << "Enter row / columns of matrix: ";
    cin >> n >> m;

    int arr[n][m];

    cout << "Enter elements in matrix:\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    // original matrix
    cout << "Original Matrix:\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Transpose matrix
    int b[m][n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            b[j][i] = arr[i][j];
        }
    }

    // transpose matrix
    cout << "Transpose Matrix:\n";
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << b[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
