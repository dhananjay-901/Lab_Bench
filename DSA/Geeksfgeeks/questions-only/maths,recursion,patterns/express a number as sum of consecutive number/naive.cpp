//given a positive integer n find whether it can be represented as the sum of two or more consecutive positive integers
//naive approach
//the idea is to start from every number and keep adding consecutive numbers until the sum becaomes equal to or greater than n. if the sum becomes equal to n return true
/*The sum of first n natural numbers is: n * (n + 1) / 2.
The sum of first (x + k) natural numbers is: (x + k) * (x + k + 1) / 2. If n is the sum of k consecutive numbers, then:
n = [(x + k)(x + k + 1) - x(x + 1)] / 2
Or, 2 * n = [(x + k)(x + k + 1) - x(x + 1)]
So, we try all possible values and check whether the condition becomes true.*/

#include <iostream>
using namespace std;

bool issumofconsecutive(int n){
    for(int i=1;i<n;i++){
        int sum=0;
        for(int j=1;j<n;j++){
            sum+=j;
            if(sum==n && j>i) return true;
            if(sum>n) break;
        }
    }
    return false;
}

int main(){
    int n=10;
    cout << ((issumofconsecutive(n)==true)?"true":"false") << " ";
}