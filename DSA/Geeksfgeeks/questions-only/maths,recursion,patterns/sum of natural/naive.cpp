//program for sum of n natural numbers
//given a positive integer n find the sum of the first n natural numbers
//naive approach
#include <iostream>
using namespace std;
int findsum(int n){
    int sum = 0;
    for(int i=1;i<=n;i++) sum = sum+i;
    return sum;
}
int main() {
    int n=100;
    cout <<findsum(n);
    return 0;
}