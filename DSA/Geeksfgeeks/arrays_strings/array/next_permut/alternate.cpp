//the idea is to use c++ in built function next permutation which directly transforms the given array into its next lexiographically greater permutation, if the current arrangement is already the largest possible, this function rearranges the array into the smallest sorted permutation
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void nextpermutation(vector<int>& arr){
    next_permutation(arr.begin(), arr.end());
}

int main(){
    vector<int> arr = {2,4,1,7,5,0};

    nextpermutation(arr);
    for(int i=0;i<arr.size();i++){
        cout << arr[i] << " ";
    }
    return 0;
}
