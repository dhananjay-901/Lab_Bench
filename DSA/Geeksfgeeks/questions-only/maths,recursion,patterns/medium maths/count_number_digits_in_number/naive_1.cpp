//naive approach 2 using recursion - the main idea is to remove digits from right by calling a recursive function for each digit. the base condition of this recursive approach is when we divide the number by 10 and then number gets reduced to 0. so returne 1 for this operation other wise keep dividing the number by 10 this reduces the input number size by 1 and keeps track of the number of sizes reduced 

#include <iostream>
using namespace std;

int countdigit(int n){
    if(n/10==0) return 1;
    return 1 + countdigit(n/10);
}

int main(){
    int n = 58964;
    cout << countdigit(n);
    return 0;
}