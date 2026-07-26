//check if two strings are same - given two strings check if these two strings are identical(same) or not. consider case sensitivity

//using == in c++, the idea is to use equality operator to compare both strings character by character. if the strings are identical, itprints "yes" other wise it prints no

#include <iostream>
using namespace std;

bool arestringssame(string s1, string s2){
    return s1 == s2;
}

int main(){
    string s1 = "abc";
    string s2 = "abcd";
    cout << ((arestringssame(s1, s2))?"yes":"no") << endl;
    return 0;
}