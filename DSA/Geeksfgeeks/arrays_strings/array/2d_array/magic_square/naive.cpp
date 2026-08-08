//given a integer n and a nxn integer matrix check the whether the matrix is a magic square o rnot. a magic square is a matrix containing distinct elements from 1 to n-n such that the sum of every row every column and both diagonals is the same

#include <iostream>
#include <vector>

using namespace std;

bool ismagicsquare(vector<vector<int>>& mat){
    int n = mat.size();
    int target = 0;

    for(int j=0;j<n;j++) target+=mat[0][j];

    vector<int> visited(n*n+1,0);

    for(int i=0;i<n;i++){
        int rowsum = 0, colsum = 0;

        for(int j=0;j<n;j++){
            rowsum+=mat[i][j];
            colsum+=mat[j][i];

            int val = mat[i][j];

            if(val<1 || val > n*n || visited[val]){
                return false;
            }
            visited[val] = 1;
        }
        if(rowsum !=target ||colsum!=target) return false;
    }

    int d1 = 0, d2 = 0;

    for(int i=0;i<n;i++){
        d1+=mat[i][i];
        d2+=mat[i][n-i-1];
    }
    return d1==target && d2 == target;
}

int main(){
    vector<vector<int>> mat = {
        {2,7,6},{9,5,1},{4,3,8}
    };

    cout << (ismagicsquare(mat) ? "magic square":"not a magic") << endl;
    return 0;
}
