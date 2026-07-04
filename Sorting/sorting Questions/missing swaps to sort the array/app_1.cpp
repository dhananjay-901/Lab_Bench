/*given an array arr[] of distinct elements, find the minimum number of swaps required to sort the array*/
//appraoch 1 is swapping elements to correct positions - the idea is to use a hash map to store each element of the given array along with its index. we also create a temporary array that stores all th elements of the input array in a sorted order. as we traverse the input array, if the current element arr[i] is not in its correct position we swap it with the element that should be at i example temp[i]. after this we increment the swap count and update the indices in the hash map accordingly

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int minswaps(vector<int>& arr){
    vector<int> temp(arr.begin(), arr.end());
    sort(temp.begin(), temp.end());

    unordered_map<int, int> pos;
    for(int i=0;i<arr.size();i++){
        pos[arr[i]]=i;
    }
    int swaps = 0;
    for(int i=0;i<arr.size();i++){
        if(temp[i]!=arr[i]){
            int ind = pos[temp[i]];
            swap(arr[i], arr[ind]);

            pos[arr[i]] = i;
            pos[arr[ind]] = ind;
            swaps++;
        }
    }
    return swaps;
}
int main(){
    vector<int> arr = {10,19,6,3,5};
    cout << minswaps(arr);
    return 0;
}