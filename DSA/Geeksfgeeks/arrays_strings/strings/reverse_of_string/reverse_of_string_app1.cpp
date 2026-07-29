//using backward traversal

#include <iostream>
#include <string>
using namespace std;
string reversestring(string& s){
    string res;
    for(int i = s.size() - 1;i >= 0; i--){
        res+= s[i];
    }
    return res;
}

int main(){
    string s = "abcdfe";
    string res = reversestring(s);
    cout << res << endl;
    return 0;
}
