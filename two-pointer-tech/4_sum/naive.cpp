/*Given an array of integers, check if there are four elements in the array with given sum.*/
/*generate all possible quadruplets and compare the sum of every quadruple with target.*/

#include <bits/stdc++.h>
using namespace std;

bool check4sum(vector<int>& arr, int target){
    int n = arr.size();
    for(int i=0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                for(int l = k + 1; l < n; l++){
                    if(arr[i] + arr[j] + arr[k] + arr[l] == target){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main(){
    vector<int> arr = {1,1,1,1,1};
    int target = 4;
    cout << (check4sum(arr, target)? "True" : "False") << "\n";
    return 0;
}   