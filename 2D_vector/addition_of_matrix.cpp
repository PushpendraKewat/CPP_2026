#include<iostream>
#include<vector>
using namespace std;

int main(){
    int r1, c1, r2, c2;

    cout << "Enter rows and columns of matrix A: ";
    cin >> r1 >> c1;

    cout << "Enter rows and columns of matrix B: ";
    cin >> r2 >> c2;

    vector<vector<int>> A(r1, vector<int>(c1));
    vector<vector<int>> B(r2, vector<int>(c2));

    // Check condition
    if(r1 != r2 || c1 != c2){
        cout << "Matrix addition not possible";
        return 0;
    }

    // Input matrix A
    cout << "Enter elements of matrix A:\n";
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            cin >> A[i][j];
        }
    }

    // Input matrix B
    cout << "Enter elements of matrix B:\n";
    for(int i=0;i<r2;i++){
        for(int j=0;j<c2;j++){
            cin >> B[i][j];
        }
    }

    // Result matrix
    vector<vector<int>> C(r1, vector<int>(c1));

    // Addition
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    // Display result
    cout << "Sum matrix:\n";
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
