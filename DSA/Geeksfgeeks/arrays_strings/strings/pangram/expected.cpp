//the idea is to create a visited array of size 26 to mark whether a character is present in the string or not. now iterate through all the characters of the string and mark them as visited. lowercase and uppercase are conisdered the same. so "A" and "a" are marked at index 0 and similar z and Z are marked at index 25. after iterating through all the characters, check whether all the characters are marked in visited array or not. if not then return false else return true

#include <iostream>
#include <vector>
using namespace std;

bool checkpangram(string& s){
    vector<bool> vis(26, false);

    for(int i=0;i<s.length();i++){
        if('A' <= s[i] && s[i] <='Z') vis[s[i] - 'A'] = true;
        else if('a' <= s[i] && s[i] <= 'z') vis[s[i] - 'a'] = true;
    }

    for(int i=0;i<26;i++){
        if(!vis[i]) return false;
    }

    return true;
}

int main(){
    string s = "the quick brown fox jumps over the lazy dog";

    cout << ((checkpangram(s))?"true" : "false");
    return 0;
}
