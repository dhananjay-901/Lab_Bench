//given two strings s1 and s2 find if the string is subsequce of the second string

#include <iostream>
#include <string>
using namespace std;

bool issubseqrec(string& s1, string& s2, int m, int n){
    if(m==0){
        return true;
    }
    if(n==0){
        return false;
    }

    if(s1[m-1] == s2[n-1]){
        return issubseqrec(s1,s2,m-1,n-1);
    }
    return issubseqrec(s1,s2,m,n-1);
}

bool issubreq(string& s1, string& s2){
    int m = s1.length();
    int n = s2.length();

    if(m>n) return false;
    return issubseqrec(s1,s2,m,n);
}

int main(){
    string s1 = "gksrek";
    string s2 = "geeksforgeeks";
    cout << ((issubreq(s1,s2))?"true":"false") << endl;
    return 0;
}
