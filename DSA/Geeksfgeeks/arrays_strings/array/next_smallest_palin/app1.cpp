//given a number in the form of an array num[] of size n containing digits from 1 to 9 inclusive. find the next smallest palindrom strictly larger than the given number

//approach - try all possible numbers
//the idea is to keep adding 1 to the number and check if the number becomes a palindrome. stop when a palindrome is found.
#include <iostream>
#include <vector>
using namespace std;

int checkpalindrome(vector<int>& num){
    int n = num.size();
    for(int i=0;i<n/2;++i){
        if(num[i] != num[n-1-i]){
            return 0;
        }
    }
    return 1;
}

vector<int> nextpalindrome(vector<int>& num){
    int n = num.size();

    while(true){
        int carry = 1;
        for(int i=n-1;i>=0;--i){
            num[i]+=carry;
            if(num[i] == 10){
                num[i] = 0;
                carry = 1;
            }else{
                carry = 0;
                break;
            }
        }

        if(carry == 1){
            num.insert(num.begin(),1);
            n++;
        }

        if(checkpalindrome(num)){
            break;
        }
    }
    return num;
}

int main(){
    vector<int> num = {9,4,1,8,7,9,7,8,3,2,2};
    vector<int> res = nextpalindrome(num);
    for(int i=0;i<res.size();++i){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
