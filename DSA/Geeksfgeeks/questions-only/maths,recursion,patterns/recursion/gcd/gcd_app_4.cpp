//optimized euclidean algorithm by checking remainder 
/*Instead of the Euclidean algorithm by subtraction, a better approach can be used. We don't perform subtraction here. we continuously divide the bigger number by the smaller number. More can be learned about this efficient solution by using the modulo operator in Euclidean algorithm*/

#include <iostream>
using namespace std;

int gcd(int a, int b){
    return b==0 ? a:gcd(b,a%b);
}
int main(){
    int a=20, b=28;
    cout << gcd(a,b);
    return 0;
}