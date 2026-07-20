//given a number n print least prime factors of all numbers from 1 to n. the least prime factor of an integer n is the smallest prime number that divides the number
//trying every number one by one
#include <iostream>
#include <vector>
using namespace std;

vector<int> leastprimefactor(int n){
    vector<int> lpf(n+1);
    lpf[0]=0;
    lpf[1]=1;

    for(int i = 2; i<=n; i++){
        bool found = false;
        for(int j=2;j*j<=i;j++){
            if(i%j==0){
                lpf[i]=j;
                found = true;
                break;
            }
        }

        if(!found) lpf[i]=i;
    }
    return lpf;
}

int main(){
    int n =6;
    vector<int> result = leastprimefactor(n);
    for(int i=0;i<=n;i++) cout << result[i]<<" ";
    return 0;
}