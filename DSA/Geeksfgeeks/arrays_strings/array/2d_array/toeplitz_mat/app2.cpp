//the core idea is to examine each cell, starting from the second row and second column we compare each cell's value with its top left neighbor. if a mismatch sif ound, the matrix is not toeplitz and we can stop. if the entire matrix is checked without any mismatches all diagonals are constant

#include <iostream>
#include <vector>
using namespace std;

bool istoeplitz(vector<vector<int>>& mat){
    int n = mat.size(), m = mat[0].size();

    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(mat[i][j] != mat[i-1][j-1]) return false;
        }
    }
    return true;
}

int main(){
    vector<vector<int>> mat = {{6, 7, 8},{4, 6, 7},{1, 4, 6}};
    if(istoeplitz(mat)) cout << "true";
    else cout << "false";
    return 0;
}
