/*The above method can be optimized based on the following idea:

If we notice the previous approach, we can see at some point, one number becomes a factor of the other so instead of repeatedly subtracting till both become equal, we can check if it is a factor of the other.*/

//approach 3 modified euclidean algorithm using subtraction by checking divisibility

#include <iostream>
using namespace std;

int gcd(int a, int b){
    if(a==0) return b;
    if(b==0) return a;
    if(a==b) return a;
    if(a>b){
        if(a%b==0) return b;
        return gcd(a-b,b);
    }
    if(b%a==0) return a;
    return gcd(a,b-a);
}

int main(){
    int a=20,b=28;
    cout << gcd(a,b);
    return 0;
}