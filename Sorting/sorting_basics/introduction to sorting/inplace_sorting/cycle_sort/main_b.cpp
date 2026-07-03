/*This method is a special optimized version of Cycle Sort that works only when array elements are in the range 1 to N or 0 to N. In this case, we do not need to explicitly detect cycles; instead, we directly place elements at their correct indices using swapping.

If elements are in range 1 to N, then: Correct index of an element = value - 1
Example: 1 -> index 0, 2 -> index 1, …, N -> index N-1

If elements are in range 0 to N, then: Correct index of an element = value itself*/

#include <bits/stdc++.h>
using namespace std;

void cyclesort(vector<int>& arr){
    int n = arr.size();
    int i = 0;
    
    while(i<n){
        int correct = arr[i] - 1;

        if(arr[i] != arr[correct]){
            swap(arr[i], arr[correct]);
        }else{
            i++;
        }
    }
}

int main(){
    vector<int> arr = {3,2,4,5,1};
    int n = arr.size();
    cyclesort(arr);
    for(int i = 0;i < n;i++){
        cout << arr[i] << "\n";
    }
    return 0;
}

/*
Advantage of Cycle Sort
Auxiliary Space is O(1)
 in-place sorting algorithm.
 A minimum number of writes to the memory
 Cycle sort is useful when the array is stored in EEPROM or FLASH. 
The idea of Cycle Sort is used in problems like Minimum Missing Positive and Min Swaps to Sort
Disadvantage  of Cycle Sort
Time complexity is O(n²) for general case
Not stable
Not suitable for large datasets
*/