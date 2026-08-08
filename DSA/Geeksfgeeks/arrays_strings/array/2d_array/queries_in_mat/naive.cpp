//given two integers m and n representing the dimensions of a matrix mat[][] of size mxn the matrix is initially filled with numbers from 1 to mxn in row major order

//naive approach - the idea is to create matrix mat[] of order m*n filled with integers from 1 to mxn sequentially in a row major order. for the queries of type 1 and 2 swap traverse required row or column and swap the each of its element and for the query of type 2 print, we simply print the element at specified index

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void swaprows(vector<vector<int>>& mat, int r1, int r2){
    for(int i=0;i<mat[0].size();i++){
        swap(mat[r1][i], mat[r2][i]);
    }
}

void swapcols(vector<vector<int>>& mat, int c1, int c2){
    for(int i=0;i<mat.size();i++){
        swap(mat[i][c1], mat[i][c2]);
    }
}

void solvequeries(int m, int n, vector<vector<int>>& query){
    vector<vector<int>> mat(m, vector<int>(n));

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            mat[i][j] = (i*n) + j + 1;
        }
    }

    for(int i=0;i<query.size();i++){
        if(query[i][0] == 1){
            swaprows(mat,query[i][1], query[i][2]);
        }
        else if(query[i][0] == 2){
            swapcols(mat, query[i][1], query[i][2]);
        }
        else{
            cout << mat[query[i][1]][query[i][2]] << " ";
        }
    }
}

int main(){
    int m = 3, n = 3;
    vector<vector<int>> query = {{1,0,1},{3,0,0},{3,1,0},{2,0,1},{3,0,0},{3,1,0}};
    solvequeries(m,n,query);
    return 0;
}
