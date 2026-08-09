#include <iostream>
#include <string>
using namespace std;

long long fact(int n){
    long res = 1;
    for(int i=2;i<=n;i++) res*=i;
    return res;
}

int findsmallerinright(string s, int low){
    int countright = 0;
    for(int i = low+1;i<s.size();++i){
        if(s[i] < s[low]) ++countright;
    }
    return countright;
}

long long findrank(string s){
    int n = s.size();
    long long rank = 1;
    int countright;

    for(int i=0;i<n;i++){
        countright = findsmallerinright(s,i);
        rank+=countright * fact(n-i-1);
    }
    return rank;
}

int main(){
    string s = "string";
    cout << findrank(s);
    return 0;
}
