//given a positive integer n, print a pyramid pattern consistig of stars* such that the number of rows equals n. the pyramid should be center aligned
//using two loops  - the idea is to use nested lopos. the outer loop is used to track the rows, while the inner loops are used to print the required sapces and stars for each row.

#include <iostream>
using namespace std;
void printpyramid(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++) cout << " ";

        for(int j=1;j<=2*i-1;j++) cout << "*";
        cout << endl;
    }
}

int main(){
    int n = 5;
    printpyramid(n);
    return 0;
}