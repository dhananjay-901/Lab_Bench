//program for armstrong numbers
//given a number x determine whether the given number is armstrong number or not. a positive number of n digits is called an armstrong number of order n 

//naive approach - the idea is to first count the number of digits.let the number of digits be n. for every digit r in input number x compute r^n. if the sum of all such values is equal to x then return true else false

#include <iostream>
using namespace std;
int power(int x, int y){
    if(y==0) return 1;
    if(y%2==0) return power(x,y/2 ) * power(x,y/2);
    return x*power(x,y/2)*power(x,y/2);
}

int order(int n){
    int t = 0;
    while (n) {
        t++;
        n=n/10;    
    }
    return t;
}

bool armstrong(int n){
    int x = order(n);
    int temp = n, sum = 0;
    while(temp){
        int r = temp%10;
        sum+=power(r,x);
        temp = temp/10;
    }
    return (sum==n);
}

int main(){
    int n = 153;
    cout << ((armstrong(n))?"true":"false");
    return 0;
}