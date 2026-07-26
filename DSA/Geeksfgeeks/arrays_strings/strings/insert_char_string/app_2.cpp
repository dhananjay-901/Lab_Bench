//using custom method
//first iterate through the given string, inserting all the characters into a new string until we reach the position where the given character needs to be inserted. at the position insert the character, and then append the remaining characters from the input string to the new string.

#include <iostream>
#include <string>
using namespace std;

string insertchar(string& s, char c, int pos){
    string res = "";
    for(int i = 0; i<s.length();i++){
        if(i==pos) res.push_back(c);
        res.push_back(s[i]);
    }

    if(pos>=s.length()) res.push_back(c);
    return res;
}

int main(){
    string s = "geeks";
    cout << insertchar(s, 'A', 3);
    return 0;
}