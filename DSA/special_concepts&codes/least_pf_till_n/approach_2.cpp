//using sieve of erastothenes - We can use a variation of sieve of Eratosthenes to solve the above problem.  Initialize an array where each number is set to itself, then iterate from 2 to n. if a number i is still equal to its value, it is prime. Since every multiple of i (2i, 3i, 4i...) is divisible by it, those numbers are not prime, so while marking these multiples we assign i as their least prime factor because i is the smallest prime dividing them. Since we only assign when a number is not already marked, the first prime that reaches a number ensures it gets its correct smallest prime factor.

#include <iostream>
#include <vector>
using namespace std;

vector<int> leastprimefactor(int n){
    vector<int> lpf(n+1);
    for(int i=0;i<=n;i++){
        lpf[i]=i;
    }
    lpf[0]=0;
    lpf[1]=1;

    for(int i=2;i<=n;i++){
        if(lpf[i]==i){
            for(int j=i*2;j<=n;j+=i){
                if(lpf[j]==j){
                    lpf[j]=i;
                }
            }
        }
    }
    return lpf;
}

int main(){
    int n =6;
    vector<int> result = leastprimefactor(n);
    for(int i=0;i<=n;i++) cout << result[i] << " ";
    return 0;
}