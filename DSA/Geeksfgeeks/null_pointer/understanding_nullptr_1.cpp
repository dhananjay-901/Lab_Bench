#include <iostream>
using namespace std;

void fun(int n){
    cout << "fun(int)"<<endl;
}
void fun(char* s){
    cout << "fun(char*)"<<endl;;
}
int main(){
    fun(nullptr);

    int* ptr = nullptr;
    if(ptr) cout << "true";
    else cout << "false";
}

//output func(char *)


/*type safety of nullptr unlike null, nullptr cannot be assigned to integer types. explanation - nullptr is strictly a pointer type. it prevents accidental integer assignments. this makes code safer and more reliable*/

//nullptr can be used in conditional statements to check pointer validity
//explanation - a null pointer evaluates to false in a conditional expression while a valid pointer evaluates to true. comparison behavior of nullptr. nullptr can be compared with pointers using  == and !=. correctly identifies whether a pointer is null or non null. can be assigned or compared with any pointer type.
