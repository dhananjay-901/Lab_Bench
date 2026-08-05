//given a string s, check if it is a pangram or not. a pangram is a sentence containing every letter in the english alphabet either in lowercase or uppercase
//the idea is to iterate over all characters from 'a' to 'z' and for each chaeracter, check if it is present in the input string or not. if nay character is not present in the input string, return false. other wise return true. also we need to ignore the case while searching for a character 'a' and 'A' are considered same.

#include <iostream>
#include <algorithm>
using namespace std;

bool checkpangram(string& s){
    for(char ch = 'a';ch<='z';ch++){
        bool found = false;

        for(int i=0;i<s.length();i++){
            if(ch==tolower(s[i])){
                found = true;
                break;
            }
        }

        if(!found){
            return false;
        }
    }
    return true;
}

int main(){
    string s = "the quick brown fox jumps over the lazy dog";
    cout << ((checkpangram(s))?"true":"False");
    return 0;
}
