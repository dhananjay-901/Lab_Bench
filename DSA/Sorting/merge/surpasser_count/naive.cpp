#include <bits/stdc++.h>
using namespace std;
//surpasser count of each element in array 
/*given an array of distinct intergers arr[], a surpasser of an element arr[i] is any element arr[j] such that j > i and arr[j]>arr[i]. find the number of surpasses for each element in the array*/

//naive approach - using two nested loops the simplest approach is to iterate through the array and for each element count the number of elements to its right that is greater than it.

vector<int> findsurpasser(vector<int>& arr){
    int n = arr.size();
    vector<int> res(n,0);
    for(int i = 0;i<n;i++){
        int count = 0;
        for(int j = i + 1; j < n; j++){
            if(arr[j]>arr[i]){
                count++;
            }
        }
        res[i] = count;
    }
    return res;
}

int main(void){
    vector<int> arr = {2,7,5,3,8,1};
    vector<int> res = findsurpasser(arr);
    for(auto count : res){
        cout << count << "\n";
    }
    return 0;
}