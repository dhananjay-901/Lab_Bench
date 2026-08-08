//to solve the question without any extra space rotate the array in form of cycles. For example, a 4 X 4 matrix will have 2 cycles. The first cycle is formed by its 1st row, last column, last row, and 1st column. The second cycle is formed by the 2nd row, second-last column, second-last row, and 2nd column. The idea is for each square cycle, to swap the elements involved with the corresponding cell in the matrix in an anticlockwise direction i.e. from top to left, left to bottom, bottom to right, and from right to top one at a time using nothing but a temporary variable to achieve this.

#include <iostream>
#include <vector>
using namespace std;

void rotatemat(vector<vector<int>>& mat){
    int n = mat.size();
    for(int i=0;i<n/2;i++){
        for(int j=i;j<n-i-1;i++){
            int temp = mat[i][j];
            mat[i][j] = mat[j][n-i-1];
            mat[j][n-1-i] = mat[n-1-i][n-1-j];
            mat[n-1-i][n-1-j] = mat[n-1-j][i];
            mat[n-1-j][i] = temp;
        }
    }
}

int main(){
    vector<vector<int>> mat = {
        {1, 2, 3, 4},                {5, 6, 7, 8},                {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    rotatemat(mat);
    for(auto& row : mat){
        for(int x : row){
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}
