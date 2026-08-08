//traverse the matrix mat[][] and for each cell find the count of live neighbours. If the cell at index {x, y} is dead (i.e. 0) and the count of live neighbors is three, set mat[x][y] = 2, which means that the cell will become alive in the next generation, but is dead for now. Else if the cell is live (i.e. 1) and the count of live neighbors is not equal to two or three, set mat[x][y] = 3, which means that the cell will be dead in the next generation, but is alive for now. After completing the traversal, traverse the matrix mat[][] once again. Set all the cells with value 2 to 1 and cells with value 3 to 0. All the remaining cells will retain there value i.e. the cells with value 0 and 1 will remain as it is.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findnextgen(vector<vector<int>>& mat){
    int m = mat.size(), n = mat[0].size();

    vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}};

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int live = 0;
            for(auto dir : directions){
                int x = i + dir[0];
                int y = j + dir[1];

                if(x >= 0 && x < m && y >= 0 && y <n && (mat[x][y] == 1 || mat[x][y] == 3)){
                    live++;
                }
            }

            if(mat[i][j]==1 && (live < 2 || live > 3)){
                mat[i][j] = 3;
            }

            else if(mat[i][j] == 0 && live == 3){
                mat[i][j] = 2;
            }
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j] == 2){
                mat[i][j] = 1;
            }
            if(mat[i][j] == 3){
                mat[i][j] = 0;
            }

            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    vector<vector<int>> mat = {{0,0,0,0},{0,0,1,0},{0,1,1,0},{0,0,0,0}};
    findnextgen(mat);
    return 0;
}
