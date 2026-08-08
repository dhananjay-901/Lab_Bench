//traverse each diagonal directly by starting from every element in the first row and then from every element in last column. [e xcept the first elemet of the last column]. from each starting point move diagonally down left and print elements until going out of bounds
#include <iostream>
#include <vector>
using namespace std;


void diagonaltrav(vector<vector<int>>& mat){
    int n = mat.size();
    for(int col=0;col<n;col++){
        int i=0, j = col;
        while(i<n && j>=0){
            cout << mat[i][j] << " ";
            i++,j--;
        }
    }
    for(int row = 1;row<n;row++){
        int i = row, j = n-1;
        while(i<n && j>=0){
            cout << mat[i][j] << " ";
            i++,j--;
        }
    }
}

int main(){
    vector<vector<int>> mat = {
        {1,2,3},{4,5,6},{7,8,9}
    };

    diagonaltrav(mat);
    return 0;
}
