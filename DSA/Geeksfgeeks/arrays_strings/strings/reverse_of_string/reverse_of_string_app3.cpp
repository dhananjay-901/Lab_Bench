//using recursion 
//the idea is to use recursion and define the recursive function that takes a string as input and reverses it. inside the recursive function
#include <iostream>
#include <vector>
using namespace std;

void reverseStringRec(string &s, int l, int r) {
    if(l >= r)
        return;
    swap(s[l], s[r]);
    reverseStringRec(s, l + 1, r - 1);
}
string reverseString(string &s) {
    int n = s.length();
    reverseStringRec(s, 0, n - 1);
  	return s;
}
int main() {
    string s = "abdcfe";
  	cout << reverseString(s) << endl;
    return 0;
}