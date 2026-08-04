//this approach iterates through the string and retains only the characters that are not equal to the given character by shifting them toward the beginning of the string. after processing all characters, the string is resized the leftover characters at the end.

#include <iostream>
using namespace std;

void removechar(string &s, char c){
    int j = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] != c){
            s[j++] = s[i];
        }
    }
    s.resize(j);
}
int main(){
    string s = "ababaca";
    char c = 'a';

    removechar(s, c);
    cout << s << endl;
    return 0;
}