#include <iostream>
#include <ctime>
#include <string>
#include <sstream>

using namespace std;

class binarymultiplier{
    public:
        string makemultiplication(string, string);
        string makeshifting(string, int);
        string addbinary(string, string);
        void binarystringtodecimal(string);
};

class karatsuba{
    public:
        int lengthcontroller(string&, string&);
        string addstrings(string, string);
        string multiply(string, string);
        string decimaltobinary(long long int);
        string subtraction(string, string);
        string makeshifting(string, int);
};

string binarymultiplier::makemultiplication(string str1, string str2){
    string allsum = "";
    for(int j=0;j<str2.length();j++){
        int seconddigit = str2[j] - '0';
        if(seconddigit == 1){
            string shifted = makeshifting(str1,str2.size() - (j+1));
            allsum = addbinary(shifted, allsum);
        }
    }
    return allsum;
}

string binarymultiplier::addbinary(string a, string b){
    string result = "";
    int s = 0;
    int i = a.size() - 1;
    int j = b.size() - 1;
    while(i>=0 || j>=0 || s==1){
        s+=((i>=0)?a[i] - '0' : 0);
        s+=((j>=0)?b[j] - '0' : 0);
        result = char(s%2 + '0') + result;
        s/=2;
        i--;
        j--;
    }
    return result;
}

string binarymultiplier::makeshifting(string str, int stepnum){
    string shifted = str;
    for(int i=0;i<stepnum;i++){
        shifted = shifted + '0';
    }
    return shifted;
}

void binarymultiplier::binarystringtodecimal(string str){
    unsigned long long int val = 0;
    for(int i=0;i<str.length();i++){
        if(str[i] == '1'){
            val = val * 2 + 1;
        }else{
            val = val * 2;
        }
    }
    cout << val << endl;
}

int karatsuba::lengthcontroller(string& str1, string& str2){
    int len1 = str1.size();
    int len2 = str2.size();
    if(len1<len2){
        for(int i=0;i<len2-len1;i++){
            str1 = '0'+str1;
        }
        return len2;
    }
    else if(len1>len2){
        for(int i=0;i<len1-len2;i++){
            str2 = '0' + str2;
        }
    }
     return len1;
}

string karatsuba::addstrings(string first, string second){
    string result;
    int length = lengthcontroller(first, second);
    int carry = 0;
    for(int i=length-1;i>=0;i--){
        int firstbit = first.at(i) - '0';
        int secondbit = second.at(i) - '0';

        int sum = (firstbit ^ secondbit ^ carry) + '0';
        result = (char)sum + result;
        carry = (firstbit&secondbit) | (secondbit&carry) | (firstbit&carry);
    }

    if(carry){
        result = '1'+result;
    }
    return result;
}

string karatsuba::decimaltobinary(long long int number){
    string result = "";
    if(number <= 0){
        return "0";
    }else{
        while(number > 0){
            long long int num = number%2;
            stringstream ss;
            ss << num;
            result = ss.str()+result;
            number = number / 2;
        }
        return result;
    }
}

string karatsuba::subtraction(string lhs, string rhs){
    int length = lengthcontroller(lhs, rhs);
    int diff;
    int borrow = 0;
    string result;

    for(int i=length-1;i>=0;i--){
        diff = (lhs[i]-'0') - (rhs[i]-'0') - borrow;
        if(diff < 0){
            diff += 2;
            borrow = 1;
        }else{
            borrow = 0;
        }
        result = char(diff + '0') + result;
    }
    return result;
}

string karatsuba::makeshifting(string str, int stepnum){
    string shifted = str;
    for(int i=0;i<stepnum;i++){
        shifted = shifted + '0';
    }
    return shifted;
}

string karatsuba::multiply(string x, string y){
    int n = lengthcontroller(x,y);
    if(n==1) return ((y[0] - '0' == 1) && (x[0]-'0'==1)) ? "1":"0";

    int fh = n/2;
    int sh = (n-fh);

    string x1 = x.substr(0,fh);
    string x2 = x.substr(fh,sh);

    string y1 = y.substr(0,fh);
    string y2 = y.substr(fh, sh);

    string p1 = multiply(x1,y1);
    string p2 = multiply(x2,y2);
    string p3 = multiply(addstrings(x1,x2), addstrings(y1,y2));

    return addstrings(addstrings(makeshifting(p1, 2*sh),p2), makeshifting(subtraction(p3,addstrings(p1,p2)), sh));
}

int main(int argc, const char * argv[]){
    string firstnumber, secondnumber;

    cin >> firstnumber;
    cin >> secondnumber;
    cout << endl;

    if(firstnumber.size()<secondnumber.size()){
        for(int i=0;i<secondnumber.size()-firstnumber.size();i++){
            firstnumber = '0' + firstnumber;
        }
    }
    else if(firstnumber.size()>secondnumber.size()){
        for(int i=0;i<firstnumber.size()-secondnumber.size();i++){
            secondnumber = '0' + secondnumber;
        }
    }

    binarymultiplier newobj;
    const clock_t classical_time = clock();
    string classic = newobj.makemultiplication(firstnumber, secondnumber);
    float c_time = float(clock()-classical_time) / CLOCKS_PER_SEC;
    cout << "classical time: " << c_time << "s, result: ";
    newobj.binarystringtodecimal(classic);

    cout << endl << "karatsuba algo" << endl;
    karatsuba obj;
    const clock_t karatsuba_time = clock();
    string karatsuba_result = obj.multiply(firstnumber, secondnumber);
    float k_time = float(clock() - karatsuba_time) / CLOCKS_PER_SEC;
    cout << "karatsuba time: " << k_time << "s, result: ";
    newobj.binarystringtodecimal(karatsuba_result);
    return 0;
}
