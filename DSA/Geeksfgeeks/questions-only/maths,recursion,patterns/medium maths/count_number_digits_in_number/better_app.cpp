//the maine idea is to use log10 to count the number of digitls of positive numbers. for negative numbers first we take absolute value of n, since logarithm is not defined for negative values

#include <iostream>
#include <cmath>
using namespace std;

int countdigit(int n){
    if(n==0) return 1;
    n = abs(n);
    return floor(log10(n)) + 1;
}

int main(){
    int n = -58964;
    cout << countdigit(n);
    return 0;
}