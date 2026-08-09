//in a circular array the maximum subarray sum can be either the maximum normal sum which is the highest sum of a non cicular array or the maximum circular sum which includes elements from both the start and the end of the array. the normal sum can be efficiently calculated using kadane's algo and the circular  sum is calculated by combininb prefix sum and suffix sum

#include <iostream>
#include <vector>
using namespace std;

int maxcircularsum(vector<int>& arr){
    int n = arr.size();
    int suffixsum = arr[n-1];

    vector<int> maxsuffix(n+1,0);
    maxsuffix[n-1] = arr[n-1];

    for(int i=n-2;i>=0;i--){
        suffixsum = suffixsum + arr[i];
        maxsuffix[i] = max(maxsuffix[i+1], suffixsum);
    }

    int circularsum = arr[0];
    int normalsum = arr[0];

    int currsum = 0;
    int prefix = 0;

    for(int i=0;i<n;i++){
        currsum = max(currsum + arr[i], arr[i]);
        normalsum = max(normalsum, currsum);

        prefix = prefix + arr[i];
        circularsum = max(circularsum, prefix + maxsuffix[i+1]);
    }
    return max(circularsum, normalsum);
}

int main(){
    vector<int> arr = {8,-8,9,-9,10,-11,12};
    cout << maxcircularsum(arr);
    return 0;
}
