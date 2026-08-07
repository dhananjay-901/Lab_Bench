//given a string s replace all the spaces in the string with '%20'

#include <iostream>
using namespace std;

string urlify(string& s){
    string res = "";
    for(int i=0;i<s.length();i++){
        if(s[i] == ' '){
            res += "%20";
        }else{
            res += s[i];
        }
    }
    return res;
}

int main(){
    string s = "i love programming";
    cout << urlify(s) << endl;
    return 0;
}