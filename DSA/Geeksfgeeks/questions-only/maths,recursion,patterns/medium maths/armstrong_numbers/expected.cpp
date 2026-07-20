//the idea is to determine if a number is an armstrong number by first converting it to a string to easily access its digits and count them. each digit is then raised to the power of the total number of digits, and then results are summed. if this sum is equal to the original number, it is classified as an asmstrong number. this approach leverages simeple strong manipulation and power calculation to perform the the check efficiently

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

bool armstrong(int n){
    string number = to_string(n);
    n = number.length();
    int output = 0;
    for(char i : number) output = output + (int)pow((i-'0'), n);
    if(output == stoi(number)) return true;
    else return false;
}

int main() {
    int n = 153;
    cout << ((armstrong(n))?"true":"false") << " ";
    return 0;
}