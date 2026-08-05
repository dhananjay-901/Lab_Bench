//we can do only with a single pass. instead of checking every subarray explicity we track of the length of increasing segments using len. when a decreasing element is encountered, we use the formula (len*(len-1))/2 to count subarrays formed by the segment and then reset len. finally we add the reamaining subarrays after the loop ends.

#include <iostream>
#include <vector>
using namespace std;

int countincreasing(vector<int>& arr){
    int n = arr.size();
    int count = 0;
    int len = 1;

    for(int i=1;i<n;i++){
        if(arr[i] > arr[i-1]){
            len++;
        }else{
            count+=(len*(len-1))/2;
            len = 1;
        }
    }

    count+=(len*(len-1))/2;
    return count;
}

int main(){
    vector<int> arr = {1,4,5,3,7,9};
    cout << countincreasing(arr) << endl;
    return 0;
}
