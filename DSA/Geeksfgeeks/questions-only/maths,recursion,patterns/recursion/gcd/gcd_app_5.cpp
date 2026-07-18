//approach 5 using built in function 
#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b){
    return __gcd(a,b);
}
int main(){
    int a =20, b= 28;
    cout<<gcd(a,b);
    return 0;
}