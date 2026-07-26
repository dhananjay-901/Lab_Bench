//the idea is to the direct string comparison function, which compares the strings character by character. if the strings are exactly the same, it returns 0. if the strings are different, returns a non zero value. based on this result, the program prints "yes" if the strings match and "no" if they don't. the comparison stops as soon as a mismatch is found or the strings end.

#include <iostream>
#include <cstring>
using namespace std;

bool arestringssame(char s1[], char s2[]){
    return strcmp(s1,s2)==0;
}

int main(){
    char s1[] = "hello";
    char s2[] = "hello";
    cout << ((arestringssame(s1, s2))?"true":"false") << endl;
    return 0;
}