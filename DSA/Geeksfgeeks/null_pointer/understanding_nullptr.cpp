/*null was traditionally used to represent null pointers.however its use can lead to ambiguity in functions overloading and unintended type conversions. to overcome these issues.
- nullptr provides a type safe null pointer representation
- it avoids unintended conversions to integer types*/

#include <bits/stdc++.h>
#include <cstddef>
using namespace std;

void fun(int N){
    cout << "fun(int)";
}

void fun(char* s){
    cout << "fun(char *)";
}
int main(){
    fun(NULL);
}
/*explanation 
- null is typically defined as 0 or (void)*0 
- it can match both int and pointer types
- this causes ambiguity in overload functions

how nullptr solves the problem 
replacing null with nullptr removes ambiguity because nullptr is a distinct pointer type.
- it is not treated as an integer
- it is only matches pointer types
- it resolves overload conflicts clearly*/