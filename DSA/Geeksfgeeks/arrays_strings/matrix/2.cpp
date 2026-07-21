#include <iostream>
#include <vector>
using namespace std;
//access elements of matrix - like one dimensional arrays, matrices can be accessed randonly by using their indices to access the individual elements. a cell has two indices, one for its row number, and the other its column number. we can use arr[i][j] to access the element which is at the ith row and jth column of the matrix

int main(){
    vector<vector<int>> arr = {{1,2,3},{4,5,6},{7,8,9}};
    cout << arr[0][0] << endl;
    cout << arr[1][2] << endl;
    cout << arr[2][1] << endl;

}