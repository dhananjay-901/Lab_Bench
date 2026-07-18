//given two integers n and m, print a hollow rectangle star pattern of the givven n rows and m colums. in this pattern, stars are printed on the boundry of the rectable while the inner area contains spaces.
//using nested loops - the pattern can be printed using two nested loops. the outer loop iterates through the rows, the inner loop iterates through the columns. a star is printed when the current position is on the first raw, last row, first column or last column otherwise a space is printed

#include <iostream>
using namespace std;

void printhollowrectangle(int n, int m){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==1||i==n||j==1||j==m) cout << "*";
            else cout << " ";
        }
        cout << endl;
    }
}

int main(){
    int n=6,m=20;
    printhollowrectangle(n, m);
    return 0;
}