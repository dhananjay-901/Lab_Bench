//print solid rectangle star pattern
//given two integers n and m print a solid rectangle of starts with n rows and m columns each row has exactly has exactly m stars
//using nestd loop - the pattern can be printed using two nested loops.the outer loop runs for each row, while the inner loops runs for each column in that row, printing stars. after printing all the stars in a row, a newline is added to move to the next row.

#include <iostream>
using namespace std;
int main(){
    int n=3,m=5;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout << "* ";
        }
        cout << "\n";
    }
    return 0;
}