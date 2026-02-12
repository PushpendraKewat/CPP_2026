#include<iostream>
#include<vector>
#include<algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

void display(vector<vector<int>>& matrix){
    for(int i=0;i<matrix.size();i++){
        for(int j =0;j<matrix.size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void rotate(vector<vector<int>>& matrix){
    // step 1 first transpose matrix
    int n = matrix.size();
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }

    cout << "\nTranspose matrix :\n";
    display(matrix);

    // // step 2  now reverse the matrix 
    // for(int i = 0; i < n; i++){
    //     std::reverse(matrix[i].begin(), matrix[i].end());
    // }
    
    // reverse matrix
    for(int i=0;i<n;i++){
        int left = 0, right = n-1;
        while(left<right){
            std::swap(matrix[i][left],matrix[i][right]);
            left++;
            right--;
        }
    }

    cout<<"\nrotate 90 matrix\n:";
    display(matrix);
}

int main(){
    int n;
    cout<<"Enter the size of matrix :";
    cin>>n;
    vector<vector<int>> matrix(n,vector<int>(n));
    int value = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            matrix[i][j] = value;
            value++;
        }
    }
    cout<<"Original matrix :\n";
    display(matrix);
    rotate(matrix);
    return 0;
}