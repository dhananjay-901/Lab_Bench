//the last bit of all odd numebrs is always 1, while for even numbers it's 0. so when performing bitwise and operation with 1 odd numebrs give 1 and even numbers give 0

//bitwise operators are extrememly fast and efficient because theu operate directly at the binary level, making them significantly faster than arithmetic or logical operations

#include <iostream>
using namespace std;

bool iseven(int n){
    if((n & 1) == 0) return true;
    else return false;
}
int main(){
    int n = 14;
    cout << ((iseven(n)==true)?"true":"false")<< "\n";
}