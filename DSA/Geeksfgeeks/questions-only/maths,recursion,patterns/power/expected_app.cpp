//expected approach using divide and conquer ologe time and ologe space 
//the idea is to use divide and conquer and recursively bisect e in two equal parts. there are two possible cases : if e is even power(b,e) = power(b,e/2) * power(b,e/2). if e is odd power(b,e) = b*power(b,e/2)*power(b*e/2)

#include <iostream>
using namespace std;

double power(double b, int e){
    if (e==0) return 1;
    if(e<0) return 1/power(b,-e);

    double temp = power(b,e/2);
    if(e%2==0) return temp * temp;
    else return b* temp * temp;
}

int main(){
    double b = 3.0;
    int e = 5;
    double res = power(b,e);
    cout << res;
    return 0;
}