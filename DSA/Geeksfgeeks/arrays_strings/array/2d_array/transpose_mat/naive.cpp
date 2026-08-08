//given a matrix mat[][] of size nxn compute its tranpose the transpose of a matrix is obtained by converting its rows into columns and its columns into rows

//naive approach - the idea is to create a new matrix where rows becomes columns by swapping indices- element at position [i][j] in the original becomes [j][i] in the transposed matrix

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> transpose(vector<vector<int>>& mat){
    int n = mat.size();
    vector<vector<int>> tmat(n, vector<int>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            tmat[j][i] = mat[i][j];
        }
    }
    return tmat;
}

int main(){
    vector<vector<int>> mat = {
        {1, 1, 1, 1},
        {2, 2, 2, 2},
        {3, 3, 3, 3},
        {4, 4, 4, 4}
    };

    vector<vector<int>> res = transpose(mat);

    for(auto& row : res){
        for(auto& elem : row){
            cout << elem << " ";
        }
        cout << "\n";
    }
    return 0;
}
