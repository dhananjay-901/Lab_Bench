//this approach is similar to the previous one but the key difference is that we are using kadane's algo to find the circular subarray sum as well. the maximum sum of a circular subarray can be defined as the total sum of the array minus the sum of a subarray in the middle. so to maximise circular subarray sum we need to minimise the subarrya sum

#include <iostream>
#include <vector>
using namespace std;

int maxcircularsum(vector<int>& arr){
    int totalsum = 0;
    int currmax = 0, currminsum = 0;
    int maxsum = arr[0], minsum = arr[0];

    for(int i=0;i<arr.size();i++){
        currmax = max(currmax + arr[i], arr[i]);
        maxsum = max(maxsum, currmax);

        currminsum = min(currminsum + arr[i], arr[i]);
        minsum = min(minsum, currminsum);

        totalsum = totalsum + arr[i];
    }

    int normalsum = maxsum;
    int circularsum = totalsum - minsum;

    if(minsum == totalsum) return normalsum;
    return max(normalsum, circularsum);
}

int main(){
    vector<int> arr = {8,-8,9,-9,10,-11,12};
    cout << maxcircularsum(arr);
    return 0;
}
