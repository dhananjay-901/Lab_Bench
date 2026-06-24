/*given an unsorted array arr[] of distinct integers construct another array countsmaller[] such that countsmaller[i] contains the counts of smaller elements on the right side of each element arr[i] in the array*/

//naive approach using nested loop 

#include <iostream>
#include <vector>
using namespace std;

vector<int> constructlowerarray(vector<int>& arr){
    int n = arr.size();
    vector<int> countsmaller(n,0);
    int i, j;

    for(i = 0;i < n; i++){
        for( j = i+1; j<n;j++){
            if(arr[j]<arr[i]){
                countsmaller[i]++;
            }
        }
    }
    return countsmaller;
}

void printarray(vector<int>& arr){
    int n = arr.size();
    for(int i=0;i<n;i++){
        cout << arr[i] << "\n";
    }
}

int main(void){
    vector<int> arr = {12,1,2,3,0,11,4};
    vector<int> low = constructlowerarray(arr);
    printarray(low);
    return 0;
}