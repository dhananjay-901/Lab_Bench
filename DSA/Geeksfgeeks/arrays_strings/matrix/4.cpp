//searching in a matrix
//we can search an element in a matrix by traversing all the elements of the matrix

#include <bits/stdc++.h>
using namespace std;

bool searchinmatrix(vector<vector<int>>& arr, int x){
    int m = arr.size(), n = arr[0].size();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==x) return true;
        }
    }
    return false;
}

int main(){
    int x = 8;
    vector<vector<int>> arr = {{0,6,8,9,11},{20,22,28,29,31},{36,38,50,61,63},{64,66,100,122,128}};
    cout << ((searchinmatrix(arr, x))?"yes":"no");
    return 0;
}