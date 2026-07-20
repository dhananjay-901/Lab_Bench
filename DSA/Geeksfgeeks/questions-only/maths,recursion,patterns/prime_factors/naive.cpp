//prime factors of a number
//given a number find all prime factors of n.
#include <iostream>
#include <vector>
using namespace std;

vector<int> primefactor(int n){
    vector<int> ans;
    for(int i=2;i<=n;i++){
        while(n%i==0 && n>0){
            ans.push_back(i);
            n=n/i;
        }
    }
    return ans;
}

int main(){
    int n = 18;
    vector<int> ans = primefactor(n);
    for(auto x : ans){
        cout << x << " ";
    }
    return 0;
}