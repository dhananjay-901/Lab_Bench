//given a number n return the count of digits in this number
//naive approach - using iterative solution 
//the main idea is to count the digits by removing the digits from the input number starting from right [least significant digit] to elft [to most significant digit] till the number is reduced to 0 we are removing digits from the right because the right most digit can be removed simple by performing integer divison by 10. 
#include <iostream>
using namespace std;

int countdigit(int n){
    if(n==0) return 1;
    int count = 0;
    while(n!=0){
        n=n/10;
        ++count;
    }
    return count;
}

int main(){
    int n = 58964;
    cout << countdigit(n);
    return 0;
}