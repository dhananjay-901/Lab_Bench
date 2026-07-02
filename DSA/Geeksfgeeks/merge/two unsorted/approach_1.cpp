//merging two unsorted arrays in sorted order
/*given two integer arrays arr1[] and arr2[] merge them into a single array such that the resulting array contains only unique elements from both arrays. additionally the final array should be sorted in ascending order.*/


/*the idea is to merge two unsorted arrays into a single list, then sort that list and remove any duplicate elements to get a sorted arrays of uniqye values*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> mergearrays(vector<int>& arr1, vector<int>& arr2){
    vector<int> res;
    int i = 0, j = 0;
    
    while(i < arr1.size()){
        res.push_back(arr1[i]);
        i++;
    }

    while(j < arr2.size()){
        res.push_back(arr2[j]);
        j++;
    }
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end()); // remove duplicates from the merged array
    return res;
}

int main(void){
    vector<int> arr1 = {11,1,8};
    vector<int> arr2 = {10,11};
    vector<int> result = mergearrays(arr1, arr2);
    for(int num : result) cout << num << "\n";
    return 0;
}