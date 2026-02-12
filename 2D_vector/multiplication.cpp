#include<iostream>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

void display(vector<vector<int>>& rows, vector<vector<int>>& columns){
    // 1st matrix
    for(int i=0;i<rows.size();i++){
        for(int j=0;j<rows[0].size();j++){
            cout<<rows[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    // 2nd matrix
     for(int i=0;i<columns.size();i++){
        for(int j=0;j<columns[0].size();j++){
            cout<<columns[i][j]<<" ";
        }
        cout<<endl;
    }
}

void multiplication(vector<vector<int>>& rows, vector<vector<int>>& columns){
    int m = rows.size();
    int n = rows[0].size();
    int p = columns.size();
    int q = columns[0].size();

    // Check multiplication condition
    if(n != p){
        cout << "\nMatrix multiplication not possible!\n";
        return;
    }

    vector<vector<int>> res(m, vector<int>(q, 0));

    // Multiply
    for(int i = 0; i < m; i++){
        for(int j = 0; j < q; j++){
            for(int k = 0; k < n; k++){
                res[i][j] += rows[i][k] * columns[k][j];
            }
        }
    }

    cout << "\nMultiplication Result:\n";
    for(int i = 0; i < m; i++){
        for(int j = 0; j < q; j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int m,n;
    cout<<"Enter the rows / colums of 1st matrix :";
    cin>>m>>n;
    vector<vector<int>> rows(m,vector<int>(n));
    int p,q;
    cout<<"Enter the rows/ columns of 2nd Matrix :";
    cin>>p>>q;
    vector<vector<int>> columns(p,vector<int>(q));
    
    // filling the value in matrix 1 and by user input

    cout<<"Enter the element of 1st matrix :\n";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>rows[i][j];
        }
    }

    cout<<"\nEnter the element of 2nd matrix :\n";
    for(int i=0;i<p;i++){
        for(int j=0;j<q;j++){
            cin>>columns[i][j];
        }
    }

    cout<<"Original both matrix :\n";
    display(rows,columns);
    multiplication(rows,columns);
    return 0;
}