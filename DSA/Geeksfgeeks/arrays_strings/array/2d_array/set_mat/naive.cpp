//given a 2d matrix mat[][] of size nxm. modify the matrix such that if mat[i][j] is 0, all the elements in the ith row and jth column are set to 0.

//the idea is to maintain two additional arrays, say rows[] and cols[] to store the rows and columns which contains at least one elements equal to 0. so first traverse the entire matrix and for each mat[i][j] = 0 mark rows[i] = true and cols[j] = true. now in the second traversal for each cell (i,j) if either rows[i] and cols[j] is marked as true, update mat[i][j] = 0 else continue to next cell

#include <iostream>
#include <vector>

using namespace std;

void setmatrixzeros(vector<vector<int>>& mat){
    int n = mat.size(), m = mat[0].size();

    vector<bool> rows(n,false), cols(m,false);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j] == 0){
                rows[i] = true;
                cols[j] = true;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(rows[i] || cols[j]) mat[i][j] = 0;
        }
    }
}

int main(){
    vector<vector<int>> mat = {{ 0, 1, 2, 0 },{ 3, 4, 0, 2 }, { 1, 3, 1, 5 }};

    setmatrixzeros(mat);
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[0].size();j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
