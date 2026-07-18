//sum of first n natural numbers = n*(n+1)/2
#include <iostream>
using namespace std;
int findsum(int n){
    return n*(n+1)/2;
}
int main(){
    int n = 5;
    cout << findsum(n);
    return 0;
}