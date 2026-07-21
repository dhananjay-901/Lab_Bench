//by using in built library function - we can also use inbuilt library functions to search for a character in a string. this makes the search simple and easier to implement 

#include <iostream>
#include <string>
using namespace std;

int findcharacterindex(const string& s, char ch){
    size_t idx = s.find(ch);
    return ((idx!=string::npos)?idx:-1);
}

int main(){
    string s = "geeksforgeeks";
    char ch = 'k';
    int index = findcharacterindex(s, ch);
    cout << index << endl;
    return 0;
}