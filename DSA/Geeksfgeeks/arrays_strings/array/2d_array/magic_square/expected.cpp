//this is mainly an optimization over the above approach, instead of doing one more iteration for diagonals, we update the diagonal sums during traversal when i==j and i+j == n-1 note that all main diagonal elements have i==j and all other diagonal elements have i+j == n-1. one more optimization we make is we can compute the target as n*(n*n+1)/2 for a magic square

#include <iostream>
#include <vector>
using namespace std;

bool ismagicsquare(vector<vector<int>>& mat){
    int n = mat.size();
    int target = n*(n*n+1)/2;

    vector<int> visited(n*n+1,0);

    int d1 = 0, d2 = 0;

    for(int i=0;i<n;i++){
        int rowsum = 0,colsum = 0;

        for(int j=0;j<n;j++){
            int valrow = mat[i][j];
            int valcol = mat[j][i];

            if(valrow < 1 || valrow>n*n || visited[valrow]) return false;
            visited[valrow] = 1;

            rowsum+=valrow;
            colsum+=valcol;

            if(i==j) d1+=valrow;
            if(i+j==n-1)  d2+=valrow;
        }

        if(rowsum!=target || colsum!=target) return false;
    }
    return d1 == target && d2 == target;
}

int main(){
    vector<vector<int>>  mat = {
        {2,7,6},{9,5,1},{4,3,8}
    };
    cout << (ismagicsquare(mat) ? "magic square" : "not a single square") << endl;;
    return 0;
}
