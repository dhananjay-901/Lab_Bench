//expected approach - the idea is similar to kadane's algorithm wth the only difference that herem, we need to keep track of the start and end of the subarray with maximum sum, this is the result array. iterate over the aray keeping track of the atrt and end of the current subarray and at any point, if the sum of current subarray becomes greater than the result array, update the result array with the current subarray.

#include <bits/stdc++.h>
using namespace std;

vector<int> maxsumsubarray(vector<int>& arr){
    int resstart = 0, resend = 0;
    int currstart = 0;

    int maxsum = arr[0];
    int maxending = arr[0];

    for(int i=1;i<arr.size();i++){
        if(maxending + arr[i] < arr[i]){
            maxending = arr[i];
            currstart = i;
        }else{
            maxending+=arr[i];
        }

        if(maxending > maxsum){
            maxsum = maxending;
            resstart = currstart;
            resend = i;
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
