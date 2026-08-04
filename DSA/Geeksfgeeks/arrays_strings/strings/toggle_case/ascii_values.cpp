//iterate through each character of the string and toggle its case using ascii vlaues subtract 32 to convert lowercase to uppercase and add 32 to convert uppercase to lowercase

#include <iostream>
using namespace std;

string togglecase(string& str){
    int ln = str.length();

    for(int i=0;i<ln;i++){
        if(str[i] >='a' && str[i] <= 'z'){
            str[i] = str[i] - 32;
        }
        else if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = str[i] + 32;
        }
    }
    return str;
}
int main(){
    string str = "geeksFORGeeks";
    string x = togglecase(str);
    cout << x << endl;
    return 0;
}