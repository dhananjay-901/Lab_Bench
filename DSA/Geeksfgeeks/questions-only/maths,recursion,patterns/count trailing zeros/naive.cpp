//the idea is to calculate the factorial of the number and then count the number of trailing zeros by repeatedlt dividing the factorial by 10 till the last digit is 0. the number of times the factorial is divided by 10 is the number of trailing zeros. this approach is not useful for large numbers as calculating their factorial will cause overflow

#include <iostream>
using namespace std;

int factorial(int n){
    int fact = 1;
    for(int i = 1;i<=n;++i){
        fact*=i;
    }
    return fact;
}

int trailingzeros(int n){
    int fact =  factorial(n);
    int count = 0;

    while(fact%10==0){
        count ++;
        fact/=10;
    }
    return count;
}

int main(){
    int n = 10;
    cout << trailingzeros(n) << endl;
    return 0;
}