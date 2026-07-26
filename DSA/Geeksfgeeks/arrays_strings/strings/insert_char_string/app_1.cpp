// we will use library methods like string insert in c++, string builder insert in java and string slicing in python

#include <bits/stdc++.h>
using namespace std;

string insertchar(string& s, char c, int pos){
    s.insert(s.begin() + pos,c);
    return s;
}
int main(){
    string s = "geeks";
    cout << insertchar(s, 'A', 3);
    return 0;
}