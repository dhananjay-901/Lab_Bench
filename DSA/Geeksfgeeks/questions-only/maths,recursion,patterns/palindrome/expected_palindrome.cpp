//check if a number is palindrome or not?
//given a integer n, determine whether it is a palindrom number or not. A number is called a palindrom if it reads the same from forward and backward

//the main idea is to find the reverse of the original number and then compare the reversed number with the original number. if the reversed number is same as the original number, the number is palindrome. otherwise the number is not a palindrome
#include <iostream>
using namespace std;

bool ispalindrome(int n){
    int reverse = 0;
    int temp = abs(n);
    while(temp!=0){
        reverse = (reverse * 10) + (temp % 10);
        temp = temp / 10;
    }
    return (reverse == abs(n));
}

int main(){
    int n = 12321;
    cout << ((ispalindrome(n)==1)?"true":"false") << " ";
    return 0;
}