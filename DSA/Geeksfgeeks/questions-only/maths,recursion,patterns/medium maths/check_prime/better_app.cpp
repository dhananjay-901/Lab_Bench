//better approach square root division 
//the idea is that we only need to check divisors up to root n while i*i <= n because divisors always comes in pairs one smaller and one larger. if a larger divisor exists beyong root n its smaller paired diviser would have already been checked making further check unncessary

#include <iostream>
#include <cmath>
using namespace std;

bool isprime(int n){
    if(n<=1) return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}

int main(){
    int n = 7;
    cout << ((isprime(n))?"true":"false") << " ";
}