//given a matrix mat[][] of dimensions n*m the task is to sort each column of a matrix in ascending order and print the updated matrix

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> transpose(const vector<vector<int>>& mat, int row, int col){
    vector<vector<int>> tr(col, vector<int>(row));

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            tr[j][i]=mat[i][j];
        }
    }
    return tr;
}

void rowwisesort(vector<vector<int>>& b){
    for(int i=0;i<(int)b.size();i++){
        sort(b[i].begin(), b[i].end());
    }
}

void sortcol(vector<vector<int>> mat, int n, int m){
    vector<vector<int>> b = transpose(mat, n, m);

    rowwisesort(b);
    mat = transpose(b, m, n);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
    vector<vector<int>> mat = {{1,6,10},{8,5,9},{9,4,15},{7,3,60}};

    int n = mat.size();
    int m = mat[0].size();

    sortcol(mat, n, m);
    return 0;
}