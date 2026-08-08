//rotating a square matrix 90 degress counterclockwise each element moves to a new position. the top row becomes the left most column in reverse order, the second row becomes the second left most column in reverse order and so on. by first reversing the rows, you rearrange the elements in such a away that when you transpose them they end up in their final rotated positions

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotatemat(vector<vector<int>>& mat){
    int n = mat.size();
    for(int i=0;i<n;i++) reverse(mat[i].begin(), mat[i].end());

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            swap(mat[i][j], mat[j][i]);
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
