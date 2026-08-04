//the core logic behind letter case toggling is based on the ascoo representation of characters. in ascii, the difference between any lowercase and its corresponding uppercase letter is always 32 for example a-A = 32 and so on. this means that toggling the 5th bit. of an alphabetic character using XOR effectively switches its case - converting lowercase to uppercase and vice versa in constant time.

#include <iostream>
using namespace std;

string togglecase(string S){
    for(auto &ch : S){
        ch^=(1<<5);
    }
    return S;
}
int main(){
    string s = "GeeksForGeeks";
    cout << togglecase(s) << endl;
    return 0; 
}