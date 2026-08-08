//The element at any position mat[x][y] in the matrix can be described as mat[x][y] = (n*x) + y + 1, where n is the count of columns. Instead of modifying the matrix directly, we can use two auxiliary arrays, rows[m] and cols[n]. The rows array is initialized with values from 0 to m-1, representing the indices of the rows, and the cols array is initialized with values from 0 to n-1, representing the indices of the columns. To process a query of type 1, which swaps rows x and y, we simply swap the values of rows[x] and rows[y]. Similarly, for a query of type 2, which swaps columns x and y, we swap the values of cols[x] and cols[y]. For a query of type 3, which print the value at position (x, y), we calculate the position using the formula, mat[x][y] = rows[x]*n + cols[y] + 1.

#include <iostream>
#include <vector>

using namespace std;

void solvequeries(int m, int n, vector<vector<int>>& query){
    vector<int> rows(m), cols(n);

    for(int i=0;i<m;i++){
        rows[i] = i;
    }
    for(int i=0;i<n;i++){
        cols[i]= i;
    }

    for(int i=0;i<query.size();i++){
        if(query[i][0] == 1){
            swap(rows[query[i][1]], rows[query[i][2]]);
        }
        else if(query[i][0] == 2){
            swap(cols[query[i][1]], cols[query[i][2]]);
        }
        else{
            cout << (rows[query[i][1]] * n) + cols[query[i][2]] + 1 << " ";
        }
    }
}

int main(){
    int m = 3, n = 3;
    vector<vector<int>> query = {{1, 0, 1}, {3, 0, 0}, {3, 1, 0}, {2, 0, 1}, {3, 0, 0},{3, 1, 0}};
    solvequeries(m,n,query);
    return 0;
}
