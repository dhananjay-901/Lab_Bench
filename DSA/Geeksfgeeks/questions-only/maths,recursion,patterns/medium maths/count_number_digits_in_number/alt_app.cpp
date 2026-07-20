// we can convert the number into a string and then find the length of the string to get the number in the original number. if the number is negative, the string will contain - sign so subtract from the length

#include <iostream>
using namespace std;

int countdigit(int n){
    string num = to_string(n);
    if(num[0]=='-') return num.length() -1;
    return num.length();
}

int main(){
    int n = -58964;
    cout << countdigit(n);
    return 0;
}