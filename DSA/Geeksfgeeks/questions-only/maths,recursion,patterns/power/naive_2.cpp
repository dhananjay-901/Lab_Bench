//naive approach 2 
//the idea is to recursively multiply b exactly e times. to do so define a recursive unfction that retur if e>0 returns 1

#include <iostream>
using namespace std;
double power(double b, int e){
    if(e==0) return 1;
    if(e<0) return 1/power(b,-e);
    return b*power(b,e-1);
}

int main(){
    double b = 3.0;
    int e = 5;
    double res = power(b,e);
    cout << res;
    return 0;
}