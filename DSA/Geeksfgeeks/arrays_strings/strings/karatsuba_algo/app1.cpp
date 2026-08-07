

#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;


int makeequallength(string& str1, string& str2){
    int len1 = str1.size();
    int len2 = str2.size();

    if(len1<len2){
        for(int i=0;i<len2-len1;i++){
            str1 = '0' + str1;
        }
        return len2;
    }
    else if(len1>len2){
        for(int i=0;i<len1-len2;i++){
            str2 = '0'+str2;
        }
    }
    return len1;
}
string addbitstrings(string first, string second){
    string result;

    int length = makeequallength(first, second);
    int carry = 0;

    for(int i=length-1;i>=0;i--){
        int firstbit = first.at(i) - '0';
        int secondbit = second.at(i) - '0';

        int sum = (firstbit ^ secondbit ^ carry) + '0';

        result = (char)sum + result;

        carry = (firstbit&secondbit) | (secondbit&carry) | (firstbit&carry);
    }
    if(carry) result = '1' + result;
    return result;
}

int multiplysinglebit(string a, string b){
    return (a[0]-'0')*(b[0]-'0');
}

long int multiply(string x, string y){
    int n = makeequallength(x,y);

    if(n==0) return 0;
    if(n==1) return multiplysinglebit(x,y);

    int fh = n/2;
    int sh = (n-fh);

    string x1 = x.substr(0,fh);
    string x2 = x.substr(fh,sh);

    string y1 = y.substr(0,fh);
    string y2 = y.substr(fh,sh);

    long int p1 = multiply(x1,y1);
    long int p2 = multiply(x2,y2);
    long int p3 = multiply(addbitstrings(x1,x2), addbitstrings(y1,y2));
    return p1*(1<<(2*sh)) + (p3-p1-p2)*(1<<sh)+p2;
}

int main(){
    printf ("%ld\n", multiply("1100", "1010"));
    printf ("%ld\n", multiply("110", "1010"));
    printf ("%ld\n", multiply("11", "1010"));
    printf ("%ld\n", multiply("1", "1010"));
    printf ("%ld\n", multiply("0", "1010"));
    printf ("%ld\n", multiply("111", "111"));
    printf ("%ld\n", multiply("11", "11"));
}
