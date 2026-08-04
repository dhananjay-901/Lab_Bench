//the idea involves initializing an empty string. iterate for loop over the given string and check character whether is lowercase or uppercase using isupper() and islower(). if lowercase converts the character to uppercase using upper() and append to emepty string, similarly with uppercase

#include <iostream>
#include <cctype>
using namespace std;

string toggleCase(string& str){
    string result = "";

    for(int i=0;i<str.length();i++){
        char ch = str[i];

        if(isupper(ch)){
            result += tolower(ch);
        }
        else if(islower(ch)){
            result += toupper(ch);
        }
    }
    return result;
}

int main(){
    string str = "geeksFORGeeks";
    string x = toggleCase(str);
    cout << x << endl;
    return 0;
}