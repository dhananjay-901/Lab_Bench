//the idea is to use the valye of i+j since elements with the same value lie on the same one place using i+j index. finally iterate over the temporary array to print the items diagonally

#include <iostream>
#include <vector>
using namespace std;

void diagonaltraversal(vector<vector<int>>& mat)
{
    int n = mat.size();
    vector<vector<int>> diag(2*n-1);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            diag[i+j].push_back(mat[i][j]);
        }
    }

    for(int d=0;d<2*n-1;d++){
        for(int val : diag[d]){
            cout << val << " ";
        }
    }
}

int main(){
    vector<vector<int>> mat = {
        {1,2,3}, {4,5,6}, {7,8,9}
    };

    diagonaltraversal(mat);
    return 0;
}
