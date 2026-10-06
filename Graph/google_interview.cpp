/* you are given m*n grid size . every cell of the grid
marks L R D U character on cell repprent 
if you are standig a that cel which 
direction you can mve to, check if 
we star from (0,0) can be reach (m-1,n-1)
 cell
constint space complexity = O(1)
*/

#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;
using std::pair;

pair<int,int> nextCell(int row, int col, vector<vector<char>>& v){
    int m = v.size();
    int n = v[0].size();

    char dir = v[row][col];

    if(dir == 'r') col++;
    else if(dir == 'l') col--;
    else if(dir == 'u') row--;
    else if(dir == 'd') row++;

    if(row < 0 || row >= m || col < 0 || col >= n){
        return {-1,-1};
    }

    return {row,col};
}

bool solve(vector<vector<char>>& v){
    int m = v.size();
    int n = v[0].size();

    pair<int,int> slow = {0,0};
    pair<int,int> fast = {0,0};

    while(true){

        if(slow.first == m-1 && slow.second == n-1){
            return true;
        }

        slow = nextCell(slow.first, slow.second, v);

        if(slow.first == -1){
            return false;
        }

        fast = nextCell(fast.first, fast.second, v);

        if(fast.first == -1){
            return false;
        }

        if(fast.first == m-1 && fast.second == n-1){
            return true;
        }

        fast = nextCell(fast.first, fast.second, v);

        if(fast.first == -1){
            return false;
        }

        if(fast.first == m-1 && fast.second == n-1){
            return true;
        }

        if(slow == fast){
            return false;
        }
    }
}

int main(){
    vector<vector<char>> v{
        {'r','r','d'},
        {'d','l','d'},
        {'u','r','l'}
    };

    if(solve(v)){
        cout << "Reachable" << endl;
    }
    else{
        cout << "Not Reachable" << endl;
    }

    return 0;
}