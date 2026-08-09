#include <iostream>
#include <vector>
using namespace std;

int area119s(const vector<int>& num){
    for(int i=0;i<num.size();++i){
        if(num[i] != 9) return 0;
    }
    return 1;
}

void nextpalindromeutil(vector<int>& num){
    int n = num.size();
    int mid = n/2;
    bool leftsmaller = false;
    int i = mid-1;
    int j = (n%2) ? mid + 1 : mid;

    while(i>=0 && num[i] == num[j]) i--,j++;

    if(i<0 || num[i] < num[j]) leftsmaller = true;

    while(i>=0){
        num[j] = num[i];
        j++;
        i--;
    }

    if(leftsmaller) {
        int carry = 1;
        i = mid - 1;
        if(n%2 == 1){
            num[mid] += carry;
            carry = num[mid] /10;
            num[mid]%=10;
            j = mid + 1;
        }else{
            j = mid;
        }

        while(i>=0){
            num[i]+=carry;
            carry = num[i]/10;
            num[i]%=10;
            num[j++] = num[i--];
        }
    }
}

vector<int> naxtpalindrome(vector<int>& num){
    vector<int> ans;
    if(area119s(num)){
        ans.push_back(1);
        for(int i=1;i<num.size();i++) ans.push_back(0);
        ans.push_back(1);
    }else{
        nextpalindromeutil(num);
        for(int i=0;i<num.size();i++){
            ans.push_back(num[i]);
        }
    }
    return ans;
}

int main(){
    vector<int> num = {9,4,1,8,7,9,7,8,3,2,2};
    vector<int> result = naxtpalindrome(num);
    for(int i : result){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
