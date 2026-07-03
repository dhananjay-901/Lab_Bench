/*In the previous approach, for every element we needed to calculate the highest element on the left and on the right. 
So, to reduce the time complexity:
=> For every element we first calculate and store the highest bar on the left and on the right (say stored in arrays left[] and right[]).
=> Then iterate the array and use the calculated values to find the amount of water stored in this index, 
which is the same as (min(left[i], right[i]) - arr[i])*/

#include <iostream>
#include <vector>
using namespace std;

int maxwater(vector<int>& arr){
    int n = arr.size();
    vector<int> left(n);
    vector<int> right(n);
    int res = 0;

    left[0] = arr[0];
    for(int i = 1; i < n; i++){
        left[i] = max(left[i-1], arr[i]);
    }
    right[n-1] = arr[n-1];
    for(int i=n-2;i>=0;i--){
        right[i] = max(right[i+1],arr[i]);
    }
    for(int i=1;i<n-1;i++){
        int minof2 = min(left[i],right[i]);
        res+=minof2 - arr[i];
    }

    return res;
}

int main(){
    vector<int> arr = {2,1,5,3,1,0,4};
    cout << maxwater(arr);
    return 0;
}