//given two numbers as string s1 and s2 calculate their product. note the numbers can be negative. there can be zeros in th beginning of the numbers 
//the idea is to simulate the manual multiplication process using string manipulation and integer arthmetic while considering the signs of the input numbers and properly handling carries 

#include <iostream>
#include <string>   
#include <vector>
using namespace std;

string multiplystrings(string s1, string s2){
    int len1 = s1.size();
    int len2 = s2.size();
    if(len1 == 0 || len2 == 0) return "0";
    int nn = 1, mm = 1;

    if(s1[0] == '-') {
        nn = -1;
    }
    if(s2[0] == '-') {
        mm = -1;
    }

    int isneg = nn*mm;

    vector<int> result(len1 + len2, 0);

    int i1 = 0;
    int i2 = 0;
    for (int i = len1 - 1; i >= 0; i--) {
        if (s1[i] == '-') continue;
        int carry = 0;
        int d1 = s1[i] - '0';
        i2 = 0;

        for (int j = len2 - 1; j >= 0; j--) {
            if (s2[j] == '-') continue;
            int d2 = s2[j] - '0';
            int sum = d1 * d2 + result[i1 + i2] + carry;
            carry = sum / 10;
            result[i1 + i2] = sum % 10;
            i2++;
        }
        if (carry > 0) result[i1 + i2] += carry;
        i1++;
    }

    int i = (int)result.size() - 1;
    while (i >= 0 && result[i] == 0) i--;
    if (i == -1) return "0";

    string s = "";
    while (i >= 0) {
        s += std::to_string(result[i--]);
    }
    if(isneg == -1) s = "-" + s;
    return s;
}

int main(){
    string s1 = "0033", s2 = "-20004";
    cout << multiplystrings(s1, s2) << endl;
    return 0;
}