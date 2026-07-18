//given two integers n and m (m!=0). find the number closest to n and divisible by m. if there is more than one such number, then output the one having maximum absolute value.

#include <cstdlib>
#include <iostream>
#include <climits>
using namespace std;

int closestnumber(int n, int m){
    int closest = 0;
    int mindifference = INT_MAX;
    for(int i=n-abs(m);i<=n+abs(m);++i){
        if(i%m==0){
            int difference = abs(n-i);
            if(difference < mindifference ||(difference == mindifference && abs(i)>abs(closest))){
                closest = i;
                mindifference = difference;
            }
        }
    }
    return closest;
}

int main(){
    int n = 13, m=4;
    cout << closestnumber(n, m) << endl;
    return 0;
}