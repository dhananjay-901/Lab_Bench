//given a character ch and a string s the task is to find the index of the first occurrence of the character in the string. if the character is not present in the string return -1;

//the idea is to traverse the input the string s and for each character, check if it is equal to the character we are searching for. if we find a match return the index of the current character. if we reach the end of the string without finding any occurrence of the character return -1

#include <iostream>
using namespace std;

int findchar(string &s, char ch){
    int n = s.length();
    for(int i=0;i<n;i++){
        if(s[i]==ch) return i;
    }
    return -1;
}

int main(){
    string s = "geeksforgeeks";
    char ch = 'k';
    cout << findchar(s, ch) << endl;
    return 0;
}