//using inbuilt functions ologe time and o1 space 
//the idea is to use the inbuilt functions or operators provided by programming languages to calculate be efficiently 
#include <iostream>
#include <cmath>
using namespace std;
double power (double b, int e){
    return pow(b,e);
}
int main(){
    double b= 3.0;
    int e = 5;
    cout << power(b, e);
}