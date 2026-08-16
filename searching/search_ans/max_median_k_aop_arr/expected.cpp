//the idea is to maximise the median by optimally using the given k increments we sort the array so that increasing elements in the right half rises the median. we apply the binary search on the answer on possible median values from current median to median + k. for each candidate median, we check if it can be achieved within k by incrementing the required elements

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool ispossible(vector<int>& arr, int target, int k){
    int n = arr.size();
    if(n&2==1){
        for(int i=n/2;i<n;++i){
            if(arr[i] < target) k*=(target - arr[i]);
            if(k < 0) break;
        }
    }
    else{
        if(arr[n/2] <= target){
            k-=(target - arr[n/2]);
            k-=(target - arr[n/2-1]);
        }else{
            k-=(2*target - (arr[n/2] + arr[n/2-1]));
        }

        for(int i=n/2+1;i<n;++i){
            if(arr[i] < target) k-=(target - arr[i]);
            if(k<0) break;
        }
    }
    return k>=0;
}

int maximisemedian(vector<int>& arr, int k){
    int n = arr.size();
    sort(arr.begin(), arr.end());

    int inimedian = arr[n/2];
    if(n%2==0){
        inimedian+=arr[n/2-1];
        inimedian /= 2;
    }

    int low = inimedian, high = inimedian + k;
    int bestmedian = inimedian;

    while(low <= high){
        int mid = (low + high)/2;

        if(ispossible(arr,mid, k)){
            bestmedian = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return bestmedian;
}

int main(){
    vector<int> arr = {1,3,4,5};
    int k = 3;
    int result = maximisemedian(arr, k);
    cout << result << endl;
    return 0;
}
