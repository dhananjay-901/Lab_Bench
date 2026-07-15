/*the idea is to check each element of array a[] and see if it is in array b[]. if it is we add it to the result array. since b[] is already sorted we use binary search to find the elements in log(n) time*/

#include <iostream>
#include <vector>
using namespace std; 

int binarysearch(vector<int>& b, int low, int high, int target){
    while(low<=high){
        int mid = (low+high)/2;
        if(b[mid]>target){
            high = mid-1;
        }
        else if(b[mid]<target){
            low = mid+1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

vector<int> intersection(vector<int>& a, vector<int>& b){
    vector<int> res;

    for(int i = 0; i < a.size(); i++){
        if(binarysearch(b, 0, b.size()-1, a[i]) != -1){
            res.push_back(a[i]);
        }
    }
    return res;
}

int main(void){
    vector<int> a = {1,2,4,5,6};
    vector<int> b = {2,4,7,9};

    vector<int> res = intersection(a, b);
    for(int i = 0; i < res.size(); i++) cout << res[i] << "\n";
    return 0;
}