#include<iostream>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main(){
    int n;
    cout << "Enter rows/columns: ";
    cin >> n;

    vector<vector<int>> v(n, vector<int>(n));

    cout << "Enter the elements in matrix:\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> v[i][j];
        }
    }

    cout << "Original matrix:\n";
    for(const auto& row : v){
        for(int x : row){
            cout << x << " ";
        }
        cout << endl;
    }

    // In-place transpose
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            std::swap(v[i][j], v[j][i]);
        }
    }

    cout << "Transpose matrix (modified original):\n";
    for(const auto& row : v){
        for(int x : row){
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
