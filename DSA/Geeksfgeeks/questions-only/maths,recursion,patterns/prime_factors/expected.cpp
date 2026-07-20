//expected approach - every composite number has at least one prime factor less than or equal to its square root. this property can be proved using a counter statement - let a and b be two factors of n such that a*b=n. if both are greater than sqrt(n), a*b>sqrt(n)*sqrt(n) which contradicts the expessions a*b=n

#include <iostream>
#include <vector>
using namespace std;

vector<int> primfactor(int n){
    vector<int> factors;
    while(n%2==0) {
        factors.push_back(2);
        n=n/2;
    }

    for(int i=3;i*i<=n;i+=2){
        while(n%i==0){
            factors.push_back(i);
            n/=i;
        }
    }

    if(n>2) factors.push_back(n);
    return factors;
}

int main(){
    int n = 18;
    vector<int> ans = primfactor(n);
    for(int factor : ans) {
        cout << factor << " ";
    }
    return 0;
}