//given a string s the task is to find the length of the string

//writing your own method - the most traditional method of finding the length of the string is by traversing each character through the loop. 

#include <bits/stdc++.h>
#include <string>
using namespace std;

int getlength(const string& s){
    int i = 0, cnt = 0;
    while(s[i]){
        i++;
        cnt++;
    }
    return cnt;
}

int main(){
    string s = "geeksforgeeks";
    cout << getlength(s) << endl;
    return 0;
}