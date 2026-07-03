/*Given an array arr[] of size n consisting of non-negative integers, where each element represents the height of a bar in an elevation map and the width of each bar is 1, determine the total amount of water that can be trapped between the bars after it rains.*/

//naive approach is two brute force
/*traverse every array element and find the highest bars ont he left and right sides. take the smaller of two heights. the difference between the smaller height and the height of the current element is the amount of water that can be stored in this array element*/

#include <iostream>
#include <vector>
using namespace std;

int maxwater(vector<int>& arr){
    int res = 0;
    for(int i=1;i<arr.size()-1;i++){
        int left = arr[i];
        for(int j=0;j<i;j++){
            left = max(left, arr[j]);
        }
        int right = arr[i];
        for(int j = i+1;j<arr.size();j++){
            right = max(right, arr[j]);
        }
        res+=(min(left, right)-arr[i]);
    }
    return res;
}

int main(){
    vector<int> arr = {2,1,5,3,1,0,4};
    cout << maxwater(arr);
    return 0;
}
