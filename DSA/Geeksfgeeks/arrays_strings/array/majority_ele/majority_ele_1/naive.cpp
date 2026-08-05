//given an array arr[] of size n, find the element that appears more than [n/2] times. if no such element exists return -1.
//the idea is to use a nested loops to count frequencies. the outer loop selects each element as a candidate and the inner loop counts how many times it appears. if any element appear more than n/2 times, it is the majority element

#include <iostream>
#include <vector>
using namespace std;

int majorityelement(vector<int>& arr){
    int n = arr.size();

    for(int i=0;i<n;i++){
        int count = 0;

        for(int j=0;j<n;j++){
            if(arr[i] == arr[j]){
                count++;
            }
        }

        if(count >n/2){
            return arr[i];
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {1,1,2,1,3,5,1};
    cout << majorityelement(arr) << endl;
    return 0;
}
