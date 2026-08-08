//in the previous approach we took two arrays to store the row's and column's status. Now instead of two auxiliary arrays, we can use the first row and first column of mat[][] to store which row elements and column elements are to be marked as zeroes. So if the first cell of a row is set to 0, then all cells of that row should be updated with 0. Similarly, if the first cell of a column is set to 0, then all cells of that column should be updated to 0. Since cell (0, 0) is first cell of the first row as well as the first column, so maintain another variable, say c0 to store the status of the first column and cell(0, 0) will store the status of the first row.

#include <iostream>
#include <vector>
using namespace std;

void setmatrixzeros(vector<vector<int>>& mat){
    int n = mat.size(), m = mat[0].size();
    int c0 = 1;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j] == 0){
                mat[i][0] = 0;
                if(j==0) c0 = 0;
                else mat[0][j] = 0;
            }
        }
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(mat[i][0] == 0 || mat[0][j] == 0){
                mat[i][j] = 0;
            }
        }
    }

    if(mat[0][0] == 0){
        for(int j=0;j<m;j++){
            mat[0][j] = 0;
        }
    }
    if(c0 == 0){
        for(int i=0;i<n;i++){
            mat[i][0] = 0;
        }
    }
}

int main(){
    vector<vector<int> > mat = { { 0, 1, 2, 0 }, { 3, 4, 0, 2 },{ 1, 3, 1, 5 } };
    setmatrixzeros(mat);
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[0].size();j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
