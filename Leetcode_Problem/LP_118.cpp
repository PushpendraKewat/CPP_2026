// Run Time Error

// class Solution {
// public:
//     long long fact(int n){
//         long long f = 1;
//         for(int i = 1; i <= n; i++){
//             f *= i;
//         }
//         return f;
//     }

//     long long combination(int n, int r){
//         return fact(n) / (fact(r) * fact(n - r));
//     }

//     vector<vector<int>> generate(int numRows) {
//         vector<vector<int>> triangle;

//         for(int i = 0; i < numRows; i++){
//             vector<int> row;
//             for(int j = 0; j <= i; j++){
//                 row.push_back(combination(i, j));
//             }
//             triangle.push_back(row);
//         }
//         return triangle;
//     }
// };
