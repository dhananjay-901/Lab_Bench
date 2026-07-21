//you are given a m liter jug and a n liter jug where 0 < m < n. noth they jugs are initially empty. the jugs don't jave markings to allow measuring smaller quantities. you have to use the jugs to measure d litres of water where d < n. determine the minimum no of operations to be performed to obtain d liters of water. the operations to be perform are - empty a jug, fill a jug, pour water from eon jug to the other until one of the jugs is either empty or full.

//get d litre in one jug only - our target amount d should be present in one jug only.

#include <bits/stdc++.h>
using namespace std;

int gcd(int m, int n){
    if(n==0) return m;
    return gcd(m,m%n);
}

bool isfeasible(int m,int n, int d){
    if(d>n&&d>m) return false;
    return ((d%gcd(m,n))==0);
}
int main(){
    int n=3,m=5,d=4;
    cout << isfeasible(m, n, d);
    return 0;
}