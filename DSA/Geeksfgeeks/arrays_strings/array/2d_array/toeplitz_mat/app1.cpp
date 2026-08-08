
//a toeplitx matrix also called a diagonal constant matrix is a matrix where elements of every individual descending diagonal are same from left to right. equivalently for any entry mat[i][j] it is same as mat[i-1][j-1] or mat[i-2][j-2] and so on. we can get better idea using that following image all the same colored cells should have same values

//traverse every doward sloping diagonal in the matrix by using each element in the first row and each element in the first column as a starting point, and verify that every element along that diagonal matches the value at its head

#include <iostream>
#include <vector>
using namespace std;

bool checkdiagonal(vector<vector<int>>& mat, int x, int y){
    int n = mat.size(), m = mat[0].size();

    for(int i=x+1,j=y+1; i<n && j<m; i++,j++){
        if(mat[i][j] != mat[x][y]) return false;
    }
    return true;
}

bool intoeplitz(vector<vector<int>>& mat){
    int n = mat.size(), m = mat[0].size();

    for(int i=0;i<n;i++){
        if(!checkdiagonal(mat,i,0)) return false;
    }
    return true;
}

int main(){
    vector<vector<int>> mat = {{6,7,8},{4,6,7},{1,4,6}};
    if(intoeplitz(mat)) cout << "true";
    else cout << "false";
    return 0;
}
