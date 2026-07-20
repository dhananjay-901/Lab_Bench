//when the input number exceeds 10^18 reversing it as an integer can cause overflow in languages like C,C++ and java. to avoid this, treat the number as a string and compare characters from both ends towards the center. if any pair of characters doesn't match it is not a palindrome

#include <iostream>
using namespace std;

bool ispalindrome(int n){
    string s = to_string(abs(n));
    int len = s.length();
    for(int i=0;i<len/2;i++){
        if(s[i]!=s[len-i-1]) return false;
    }
    return true;
}

int main(){
    int n = 12321;
    cout << ((ispalindrome(n))?"true":"false") << " ";
    return 0;
}