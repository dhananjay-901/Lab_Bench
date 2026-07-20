//given two integers n and m representing the dimensions of a chessboard find the number of ways to place one black knight and one white knight on the chessboard such that they cannot attack each other. the knights have to be places on different squares. a knight can more squares and one square. knights attack each other if one can reach other in one move

// the idea is to count total ways to place two knights on the board and subtract the number of attacking pairs. for every cell, we calculate how many valid knights moves it can make (onlu in one direction set to aoiv double counting)

#include <iostream>
using namespace std;

int numofways(int n, int m){
    int x_axis[]{-2,-1,1,2};
    int y_axis[]{1,2,2,1};

    long long total = m*n;
    total = total * (total-1);

    long long ret = 0;
    for(int i = 0;i<m;++i){
        for(int j=0;j<n;++j){
            for(int k =0;k<4;++k){
                int x = i+ x_axis[k], y = j + y_axis[k];
                if(x>=0 && x<m && y>=0 && y<n) ret +=2;
            }
        }
    }
    return total - ret;
}
int main(){
    int n = 2, m = 3;
    cout << numofways(n,m) << endl;
    return 0;
}