//the key idea is after each elimination the circle shrinks bu the pattern of safe positions stays the same it's just rotated. so if we know the safe position for n-1 people. we can shift it forward by k positions to get the sakfe position for n people. repeat this shrinking and shifting idea until only 1 person remains which is trivially safe.

#include <iostream>
using namespace std;

int josephus(int n, int k){
    if(n==1) return 1;
    else return (josephus(n-1, k)+ k-1)%n+1;
}
int main(){
    int n=7,k=3;
    cout << josephus(n, k);
    return 0;
}