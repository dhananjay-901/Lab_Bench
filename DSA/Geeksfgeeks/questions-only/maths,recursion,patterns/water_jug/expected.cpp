//the problem can be represented using a diophantime equation of the form m*x+n*y = d. here m litre jug is used x times and n litre jug is used by y times. also x y can be negative because of emptying. a solution exists only if gcd[m,n] divides d. the extended euclidean algorithm can be used to find values of x and y which indicate how many times each jug is filled or emptied. however this doesnot directly give the minium nuumber of steps. when solving the water jug problem we are repeatedly - adding water in chunks of m or n . removing water in chunks of m or n. therefore the final amount d is essentially formed by combining multiplies of m and n

#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}
int pour(int fromcap, int tocap, int d){
    int from = fromcap, to = 0;
    int step = 1;
    while(from!=d&&to!=d){
        int temp = min(from, tocap -to);
        to+=temp;
        from-=temp;
        step++;

        if(from == d || to == d) break;
        if(from==0) {
            from = fromcap;
            step++;
        }
        if(to==tocap){
            to=0;
            step++;
        }
    }
    return step;
}

int minsteps(int m, int n, int d){
    if(m>n) swap(m,n);
    if(d>n) return -1;

    if(d%gcd(m,n)!=0) return -1;
    return min(pour(n,m,d),pour(m,n,d));
}

int main(){
    int m = 3, n = 5, d = 4;
    cout << minsteps(m, n, d);
    return 0;
}