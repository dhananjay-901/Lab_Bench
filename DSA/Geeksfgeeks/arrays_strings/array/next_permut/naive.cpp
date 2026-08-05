//given an array of integers arr[] represting a permutation, find the next lexiographically greater permutation by rearranging the elements of the array. if such a permutation does not exist, rearrange the elements to form the lowest possible order
//the idea is that we would first generate all possible permutations of a given array and sort them. once sorted we locate the current permutation within this list. the next permutation is simply the next arrangement in the sorted order. if the current arrangement is the last in the list them display the first permutation (smallest permutation)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void generatepermutatios(vector<vector<int>>& res, vector<int>& arr, int idx){
    if (idx == arr.size()-1){
        res.push_back(arr);
        return;
    }
    for(int i=idx;i<arr.size();i++){
        swap(arr[idx], arr[i]);
        generatepermutatios(res,arr,idx+1);
        swap(arr[idx], arr[i]);
    }
}

void nextpermutation(vector<int>& arr){
    vector<vector<int>> res;

    generatepermutatios(res, arr, 0);
    sort(res.begin(), res.end());

    for(int i=0;i<res.size();i++){
        if(res[i] == arr){
            if(i<res.size()-1){
                arr = res[i+1];
            }else{
                arr = res[0];
            }
            break;
        }
    }
}

int main(){
    vector<int> arr = {2,4,1,7,5,0};
    nextpermutation(arr);
    for(int i=0;i<arr.size();i++){
        cout << arr[i] << " ";
    }
    return 0;
}
