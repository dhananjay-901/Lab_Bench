//prime factorization for multiple queries using sieve 
/*given an array arr[] of integers, find the prime factorization of each number efficiently using sieve that stores the smallest prime factor

approach - to solve this problem we first need the smallest prime factor of each number as spf alows us to repeatedly divide a by its smallest prime factor until it becomes 1, through which we can easily gets its prime factors. to calculate to smallest prime factor for every number we will use the modified approach of sieve of eratosthenes. the key idea is to precompute the smallest prime number that divides each number. once this spf array is prepeared the a factorization function will calculate the prime factors of the integers of the array.*/

#include <iostream>
#include <vector>
using namespace std;

#define MAXN 10001
vector<int> spf(MAXN + 1,1);

void sieve(){
    spf[0] = 0;
    for(int i=2;i<=MAXN;i++){
        if(spf[i]==1){
            for(int j=i;j<=MAXN;j+=i){
                if(spf[j]==1) spf[j]=i;
            }
        }
    }
}

vector<vector<int>> getfactorization(vector<int> arr){
    sieve();
    vector<vector<int>> ret;
    for(int i=0;i<arr.size();i++){
        vector<int> pfactors;
        int x = arr[i];
        while(x!=1){
            pfactors.push_back(spf[x]);
            x/=spf[x];
        }
        ret.push_back(pfactors);
    }
    return ret;
}

int main(){
    vector<int> arr = {15,17,21};
    vector<vector<int>> pfactors = getfactorization(arr);

    for(int i=0;i<pfactors.size();i++){
        for(int j=0;j<pfactors[i].size();j++){
            cout << pfactors[i][j] << " ";
        }
    }
    cout << endl;
    return 0;
}