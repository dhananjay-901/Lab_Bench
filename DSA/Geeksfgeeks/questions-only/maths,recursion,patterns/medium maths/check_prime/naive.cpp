//given a number n check whether it is a prime number or not. note a prime number is a number greater than 1 that has no positive divisors other than 1 and itself

//to check if a number n is prime, first see if it's less than 2 - if so it's not prime. otherwise try dividing n by every number from 2 to n-1. if any number divides it evenly then n is not prime. if none do then n is a prime number

#include <iostream>
using namespace std;

bool isprime(int n){
    if(n<=1) return false;
    for(int i=2;i<n;i++){
        if(n%i==0) return false;
    }
    return true;
}

int main(){
    int n = 7;
    cout << ((isprime(n))?"true":"false") << " ";
    return 0;
}