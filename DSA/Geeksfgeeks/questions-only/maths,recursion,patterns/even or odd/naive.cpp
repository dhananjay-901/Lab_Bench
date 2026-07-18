//given a number n check whether it is even or odd return true for even and false for odd

//naive approach - we can check the remainder when divided by 2. if the remainder is 0. the number is even otherwise it is odd. for example when we divide 13 by 2 we get remainder as 1 and when we divide 14 by 2 we get remainder as 0

#include <iostream>
using namespace std;

bool iseven(int n){
    int rem = n%2;
    if(rem==0) return true;
    else return false;
}

int main(){
    int n = 15;
    cout << (iseven(n) ? "true" : "false") << "\n";
    return 0;
}