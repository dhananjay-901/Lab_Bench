/*the main idea of this approach is to first move all positive integers to the left side of the array. then for the left segment it marks the presence of a number val(where 1<=val<=k) by making the element at index(val-1) negative. this marking helps identify which numbers are present. finally it scans the marked segment to find the first index that remains positive indicating the smallest missing positive number. if all positions are marked, the missing number is k+1*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr){
    int pivotidx = 0;
    int n = arr.size();
    for(int i=0;i<n;i++){
        if(arr[i]>0){
            swap(arr[i], arr[pivotidx]);
            pivotidx++;
        }
    }
    return pivotidx;
}

int missingnumber(vector<int>& arr){
    int k = partition(arr);
    for(int i=0;i<k;i++){
        int val = abs(arr[i]);
        if(val-1<k && arr[val-1]>0){
            arr[val-1] = -arr[val-1];
        }
    }

    for(int i=0;i<k;i++){
        if(arr[i]>0){
            return i+1;
        }
    }
    return k+1;
}
int main(){
    vector<int> arr = {2,-3,4,1,1,7};
    cout << missingnumber(arr);
    return 0;
}