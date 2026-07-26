#include <iostream>
#include <string>
using namespace std;

string concat(string s1, string s2){
    string res;
    for(char c : s1) res+=c;
    for(char c : s2) res+=c;
    return res;
}

int main(){
    string s1 = "hello ";
    string s2 = "world";
    string res = concat(s1, s2);
    cout << res << endl;
    return 0;
}