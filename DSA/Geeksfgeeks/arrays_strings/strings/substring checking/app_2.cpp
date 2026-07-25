//using in built library function 
#include <iostream>
using namespace std;

int main() {
    string txt = "geeksforgeeks";
    string pat = "eks";
    size_t idx = txt.find(pat);
  
    if(idx != string::npos)
        cout << idx;
    else
        cout << -1;

    return 0;
}