#include <iostream>
using namespace std;

int main(){
    const char* str = "hello, world";
    str[0] = 'h'; //error assignment to read only
    cout << str;
    return 0;
}