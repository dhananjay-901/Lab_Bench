//naive approach 1 using iteration Oe time and o1 space 
#include <iostream>
#include <cmath>
using namespace std;
double power(double b, int e){
    double pow = 1;
    for(int i=0;i<abs(e);i++){
        pow = pow*b;
    }
    if(e<0) return 1/pow;
    return pow;
}
int main(){
    double b = 3.0;
    int e = 5;
    double res = power(b,e);
    cout << res;
    return 0;
}