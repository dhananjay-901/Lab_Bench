//given a matrix mat[][] of size mxn each cell represents the state of call in a generatio 1 - live cell and 0 - dead cell. the matrix represents the current generation compute the next genration based on the following rules - any live cells with fewer that two live neighbours dies under population. any live cell with two or three live neighbours survives to the next generation. any live cell with more than three live neighbours dies over population. any dead cell with exactly three live neighbours becomes a live cell

//create a auxiliary matrix netgen[][] of order m x n to store the cells of next generation. after creating the matrix nextgen[][] traverse the matrix mat[][] and for each cell find the count of live neighbours. if the cell at index x,y is dead and the count of live neighbours is three set the nextgen[x][y] = 1. which means that cell is will becomes alive in the next genration. else if the cell is live and the count of live neighbours is not equal to two or three set nextgen[x][y] = 0 which means thta the cell will be dead in next generation. after completing the traversal return the matrix nexgen[][].

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> findnextgen(vector<vector<int>>& mat){
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> nextgen(m, vector<int>(n,0));

    vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}};

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int live = 0;
            for(auto dir : directions){
                int x = i+dir[0];
                int y = j+dir[1];

                if(x>=0 && x<m && y>=0 && y<n && (mat[x][y]==1)){
                    live++;
                }
            }
            if(mat[i][j] == 1 && (live < 2 || live > 3)){
                nextgen[i][j] = 0;
            }
            else if (mat[i][j] == 0 && live == 3){
                nextgen[i][j] = 1;
            }
            else{
                nextgen[i][j] = mat[i][j];
            }
        }
    }
    return nextgen;
}

int main(){
    vector<vector<int>> mat = {
        {0,0,0,0},{0,0,1,0},{0,1,1,0},{0,0,0,0}
    };

    vector<vector<int>> nextgen = findnextgen(mat);

    for(int i = 0;i<nextgen.size();i++){
        for(int j=0;j<nextgen[0].size();j++){
            cout << nextgen[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
