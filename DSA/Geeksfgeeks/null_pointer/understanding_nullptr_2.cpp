#include <bits/stdc++.h>
using namespace std;
int main(){
    nullptr_t np1, np2;
    // relational operators (>, <, >=, <=) are not defined for nullptr_t
    // use equality to check if both are the same null pointer
    if(np1 == np2) cout << "can compare (equal)" << endl;
    else cout << "can not compare" << endl;

    char *x = np1;
    if(x == nullptr) cout << "x is null" << endl;
    else cout << "x is not null" << endl;
    return 0;
}