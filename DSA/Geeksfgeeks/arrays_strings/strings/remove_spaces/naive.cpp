//given a string s, remove all spaces from the string and return it
//traverse the string and whenever a space is found, shift all the following characters one position to the left and reduce the effective length of the string

#include <iostream>
#include <string>

using namespace std;

string removespace(string& s){
    int n = s.length();

    for(int i=0;i<n;i++){
        if(s[i] == ' '){
            for(int j=i;j<n-1;j++){
                s[j] = s[j+1];
            }
            n--;
            i--;
        }
    }
    return s.substr(0,n);
}

int main(){
    string s = "g eeks for ge eeks ";
    cout << removespace(s) << endl;
    return 0;
}
