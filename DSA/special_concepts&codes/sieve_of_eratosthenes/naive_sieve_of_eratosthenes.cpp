//given a number n find all prime numbers less than or equal to n.
//naive approach using loop o1 space - the naive approach for finding all prime numbers from 1 to n involves chceking each number individually to determine whether it is prime 

#include <iostream>
#include <vector>
using namespace std;

bool isprime(int num){
    if(num<2) return false;
    for(int i=2;i*i<=num;i++) {
        if(num%i==0) return false;
    }
    return true;
}

vector<int> sieve(int n){
    vector<int> res;
    for(int i=2;i<=n;i++){
        if(isprime(i)){
            res.push_back(i);
        }
    }
    return res;
}

int main(){
    int n = 35;
    vector<int> res = sieve(n);
    for(auto ele : res){
        cout << ele << ' ';
    }
    return 0;
}