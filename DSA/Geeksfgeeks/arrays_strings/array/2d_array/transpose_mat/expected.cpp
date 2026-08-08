//this approach works only for square matrices where the number of rows is equal to the number of columns. it is called an in place alogrithm because it performs the transposition without using any extra space

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> transpose(vector<vector<int>>& mat){
    int n = mat.size();

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            swap(mat[i][j], mat[j][i]);
        }
    }
    return mat;
}

int main(){
    vector<vector<int>> mat = {
        {1, 1, 1, 1},
        {2, 2, 2, 2},
        {3, 3, 3 ,3},
        {4, 4, 4, 4}
    };

    vector<vector<int>> res = transpose(mat);

    for(const auto& row : res){
        for(int elem : row){
            cout << elem << " ";
        }
        cout << endl;
    }
    return 0;
}
