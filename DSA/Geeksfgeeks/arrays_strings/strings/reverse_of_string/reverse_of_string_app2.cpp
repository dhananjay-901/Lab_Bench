//start from both ends of the string and keep swapping characters while moving toward the center. each swap places the correct character in its reversed positions and when both pointers meet in the middle, the entire string becomes reversed.
//

#include <iostream>
using namespace std;

string reversestring(string& s){
    int left = 0, right = s.length()-1;

    while(left<right){
        swap(s[left], s[right]);
        left++;
        right--;
    }
    return s;
}

int main(){
    string s = "adcdef";
    cout << reversestring(s);
    return 0;
}
