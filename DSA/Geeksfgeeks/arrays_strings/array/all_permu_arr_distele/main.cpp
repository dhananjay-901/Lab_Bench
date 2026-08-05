//given an array arr[] generate all possible permutations of the elements in the array. note all elements in the array are distinct

//approach using recursion - the idea is to fix one element at a time and recursively generate permutations for the rest. at each step, we swap the current elements with another explore further recursively and then backtrack by swapping back.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void permutations(vector<vector<int>>& res, vector<int> arr, int idx){
    if(idx==arr.size()){
        res.push_back(arr);
        return;
    }

    for(int i=idx;i<arr.size();i++){
        swap(arr[idx], arr[i]);
        permutations(res,arr, idx+1);
        swap(arr[idx], arr[i]);
    }
}

vector<vector<int>> permutedist(vector<int>& arr){
    vector<vector<int>> res;
    permutations(res,arr,0);
    return res;
}

int main(){
    vector<int> arr = {1,2,3};
    vector<vector<int>> res = permutedist(arr);
    for(auto x : res){
        for(auto y:x){
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}
