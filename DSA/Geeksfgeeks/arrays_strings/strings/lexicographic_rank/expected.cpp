//create a frequency array to store character counts and covert it into a cumulative array to efficiently find how amny characters are smaller than the current character, updating if after each index during iteration

#include <iostream>
#include <string>
#include <vector>
using namespace std;

long long fact(int n){
    long long res = 1;
    for(int i=2;i<=n;i++) res*=i;
    return res;
}

long long findrank(string& s){
    int n = s.size();
    long long mul = fact(n);
    long long rank = 1;

    vector<int> count (26,0);

    for(int i=0;i<n;i++){
        ++count[s[i] - 'a'];
    }
    for(int i=1;i<26;++i){
        count[i]+=count[i-1];
    }

    for(int i=0;i<n;++i){
        mul/=(n-i);

        int charindex = s[i] - 'a';

        if(charindex>0){
            rank+=count[charindex-1]*mul;
        }
        for(int j=charindex;j<26;++j){
            --count[j];
        }
    }
    return rank;
}

int main(){
    string s = "string";
    cout << findrank(s);
    return 0;
}
