//using iteration - the idea is to iterate over all the numbers from 1 to n and for each number check if the number divides n. if the number divides n print it
#include <iostream>
#include <vector>
using namespace std;
vector<int> getdivisor(int n){
    vector<int> divisors;
    for(int i=1;i<=n;i++){
        if(n%i==0) divisors.push_back(i);
    }
    return divisors;
}

int main(){
    vector<int> divisors = getdivisor(10);
    for(auto x : divisors) cout << x << " ";
    return 0;
}