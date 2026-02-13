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

void spiral(vector<vector<int>>& v){
    int m = v.size();     // rows
    int n = v[0].size();  // columns

    int sr = 0, er = m - 1;
    int sc = 0, ec = n - 1;

    while(sr <= er && sc <= ec){

        // left → right
        for(int j = sc; j <= ec; j++){
            cout << v[sr][j] << " ";
        }
        sr++;

        // top → bottom
        for(int i = sr; i <= er; i++){
            cout << v[i][ec] << " ";
        }
        ec--;

        // from bottom right to left
        if(sr <= er){
            for(int j = ec; j >= sc; j--){
                cout << v[er][j] << " ";
            }
            er--;
        }

        // from bottom → top
        if(sc <= ec){
            for(int i = er; i >= sr; i--){
                cout << v[i][sc] << " ";
            }
            sc++;
        }
    }
}


int main(){
    int m,n;
    cout << "Enter the rows/columns of matrix : ";
    cin >>m>>n;

    vector<vector<int>> v(m, vector<int>(n));

    cout << "Enter the elements in matrix:\n";
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> v[i][j];
        }
    }

    cout << "\nOriginal matrix:\n";
    display(v);

    spiral(v);

    return 0;
}