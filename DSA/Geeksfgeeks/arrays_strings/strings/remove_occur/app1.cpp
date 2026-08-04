//given a string and a character removes all the occurences of the character from the string 

//the approach uses the build in replace() function. it directly replaces all occurences of the given character with an empty string. effectively removing them from the string

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string s = "ababaca";
    char c = 'a';

    s.erase(remove(s.begin(), s.end(), c), s.end());
    cout << s << endl;
    return 0;
}