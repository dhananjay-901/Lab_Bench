//traverse the string using two indices, where one index reads each character and the other writes only non space characters. whenever a non space character is found, place it at the write index and move both pointers accordingly. this way all non space characters are shifted forward without using extra space


#include <iostream>
#include <string>
using namespace std;

string removespace(string& s){
    int n = s.length();
    int i=0, itr = 0;

    while(i<n){
        if(s[i] != ' '){
            s[itr++] = s[i];
        }
        i++;
    }
    return s.substr(0,itr);
}

int main(){
    string s = "g eeks for ge eeks";
    cout << removespace(s) << endl;
    return 0;
}
