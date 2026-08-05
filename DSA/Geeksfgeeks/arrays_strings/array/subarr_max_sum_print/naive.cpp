//given an array arr[] the task is to print the subarray having maximum sum.
//the idea is to run two nested loops to iterate over al possible subarrays and find the maximum sum. the outer loop will mark the starting point of a subarray and inner loop will mark  the ending point of the subarray. at any time, if we find a subarray whose sum is greater than the maximum sum so far, then we will update the starting and ending point of the maximum sum subarray
#include <bits/stdc++.h>
using namespace std;

vector<int> maxsumsubarray(vector<int>& arr){
    int resstart = 0, resend = 0;
    int maxsum = arr[0];

    for(int i=0;i<arr.size();i++){
        int currsum = 0;
        for(int j=i;j<arr.size();j++){
            currsum+=arr[j];
            if(currsum>maxsum){
                maxsum = currsum;
                resstart = i;
                resend = j;
            }
        }
    }

    vector<int> res;

    for(int i=resstart;i<=resend;i++){
        res.push_back(arr[i]);
    }
    return res;
}

int main(){
    vector<int> arr = {2,3,-8,7,-1,2,3};
    vector<int> res = maxsumsubarray(arr);
    for(int i=0;i<res.size();i++){
        cout << res[i] << " ";
    }
    return 0;
}
