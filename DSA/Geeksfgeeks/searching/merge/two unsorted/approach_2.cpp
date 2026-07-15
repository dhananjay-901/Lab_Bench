/*firs sort and then merge*/
/*first sorts both input arrays individually. then merge them into a result array by comparing elements one by one frmo both sorted arrays, maintaining the overall sorted order. any remaining elements from either array are appended after one finishes*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> mergesort(vector<int>& arr1, vector<int>& arr2){
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    vector<int> res;
    int i = 0, j = 0;

    while(i < arr1.size() && j < arr2.size()){
        int val;
        if(arr1[i]<=arr2[j]){
            val = arr1[i++];
        }
        else{
            val = arr2[j++];
        }
        if(res.empty() || res.back()!=val){
            res.push_back(val);
        }
    }

    while(i < arr1.size()){
        if(res.empty() || res.back() != arr1[i]){
            res.push_back(arr1[i]);
        }
        i++;
    }

    while(j < arr2.size()){
        if(res.empty() || res.back() != arr2[j]){
            res.push_back(arr2[j]);
        }
        j++;
    }
    return res;
}

int main(void){
    vector<int> arr1 = {11,1,8};
    vector<int> arr2 = {10,11};

    vector<int> result = mergesort(arr1, arr2);
    for(int num:result) cout << num << " ";
    return 0;
}