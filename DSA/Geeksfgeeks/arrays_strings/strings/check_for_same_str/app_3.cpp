//writing your own method. if their lengths are the same. if the lengths differ, the strings cannot be identical, so it returns false. then compares each character of the two strings one by one. if any mistach is found, it returns false. if no diferences are found throughout the comparison it returns true.

#include <iostream>
using namespace std;

bool arestringsequal(string &s1, string &s2){
    if(s1.length()!=s2.length()) return false;
    for(size_t i=0;i<s1.length();++i){
        if(s1[i]!=s2[i]){
            return false;
        }
    }
    return true;
}
int main(){
    string s1 = "hello";
    string s2 = "hello";
    cout << ((arestringsequal(s1, s2))?"true":"false");
    return 0;
}