//the idea is to simulate the spiral traversal by marketing the cells that have already been visited. we can use a direction array to keep track of the movement (right, down,left, up) and change direction when we hit the boundry or a visited cells
#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralmatrix(vector<vector<int>>& mat){
    int m = mat.size();
    int n = mat[0].size();
    vector<int> res;
    vector<vector<bool>> vis(m, vector<bool>(n,false));

    vector<int> dr = {0,1,0,-1};
    vector<int> dc = {1,0,-1,0};

    int r = 0, c = 0;

    int idx = 0;
    for(int i=0;i<m*n;++i){
        res.push_back(mat[r][c]);
        vis[r][c] = true;

        int newr = r+dr[idx];
        int newc = c+dc[idx];

        if(0 <= newr && newr < m && 0 <= newc && newc < n && !vis[newr][newc]){
            r = newr;
            c = newc;
        }else{
            idx = (idx+1)%4;
            r+=dr[idx];
            c+=dc[idx];
        }
    }
    return res;
}

int main(){
    vector<vector<int>> mat = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    vector<int> res = spiralmatrix(mat);
    for(int num : res){
        cout << num << " ";
    }
    return 0;
}
