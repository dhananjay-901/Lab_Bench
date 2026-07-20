//the sieve of eratosthenes - this efficiently finds all primes upto n by repeatedly makring multiples of each prime as non prime, starting from 2. this avoids redundant checks and quickly filters out all composite numbers 

#include <iostream>
#include <vector>
using namespace std;

vector<int> sieve(int n){
    vector<bool> prime(n+1, true);
    for(int p=2;p*p<=n;p++){
        if(prime[p]== true){
            for(int i=p*p;i<=n;i+=p) prime[i] = false;
        }
    }

    vector<int> res;
    for(int p=2;p<=n;p++){
        if(prime[p]){
            res.push_back(p);
        }
    }
    return res;
}

int main(){
    int n=35;
    vector<int> res = sieve(n);
    for(auto ele: res){
        cout << ele << ' ';
    }
    return 0;
}