//string concatenation is the process of joining two strings end to end to form a single string 

#include <iostream>
#include <string>
using namespace std;

int main(){
    string s1 = "hello, ";
    string s2 = " world!";
    string res = s1 + s2;
    cout << res << endl;
    return 0;
}