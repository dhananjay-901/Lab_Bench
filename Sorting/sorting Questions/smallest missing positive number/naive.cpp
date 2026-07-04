/*given an unsorted array arr[] with both positive and negative elements, find the smallest positive number missing from the array*/
//naive approach's idea is to sort the array and assume the missing number as 1. now interate over the array and for each element arr[i]. if arr[i] == missing number. then increment missing number by 1. if arr[i] < missing number then continue to search for the missing number. if arr[i] > missing number then break and return the missing number.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int missingnumber(vector<int>& arr){
    sort(arr.begin(), arr.end());
    int res = 1;
    for(int i=0;i<arr.size();i++){
        if(arr[i] == res) res++;
        else if(arr[i]> res){
        break;}
    }
    return res;
}

int main(){
    vector<int> arr = {2,-3,4,1,1,7};
    cout << missingnumber(arr);
    return 0;
}