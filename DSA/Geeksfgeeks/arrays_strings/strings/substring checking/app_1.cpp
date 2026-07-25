//given two strings txt and pat, the task is to find if pat is a substring of txt, if yes return the index of the first occurrence else return -1

//the basic idea is to iterate through a loop in the string text and for every index in the string txt, chcek whether we can match pat starting from this index. this can be done by running a nested loop for traversing the straing pat and checking for each character of pat matches with txt or not. if all character of pat matches then return the starting index of such substring

#include <iostream>
using namespace std;

int findsubstring(string &txt, string &pat){
    int n = txt.length();
    int m = pat.length();

    for(int i=0;i<=n-m;i++){
        int j;
        for(j=0;j<m;j++){
            if(txt[i+j]!=pat[j]) break;
        }
        if(j==m){
            return i;
        }
    }
    return -1;
}

int main(){
    string txt = "geeksforgeeks";
    string pat = "eks";
    cout << findsubstring(txt, pat);
    return 0;

}