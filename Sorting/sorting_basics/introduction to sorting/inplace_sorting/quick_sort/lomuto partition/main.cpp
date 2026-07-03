/*Given an array arr[], partition the array by assuming last element as pivot element. The partition of an array must satisfy the following two conditions: Elements smaller than the pivot element appear before pivot in the array. Elements larger than or equal to the pivot element appear after pivot it in the array. Note: There might me more than one possible partition arrays.*/

//lomuto algorithm for array partition - the lomuto algorithm divides an array based on a pivot element. one pointer marks the boundry for elements smaller than the pivot, while the other pointer helps in array traversal. as we traverse the array, smaller elements are moved to the left of the boundry and boudnry expands. after the traversal, all elements to the left of the boundry are smaller and those on the right are larger than pivot

/*Step-by-step explanation of algorithm:

Choose the last element of the array as the pivot.
Initialize pointer i at the start; it represents the boundary of elements strictly smaller than the pivot.
Traverse the array using pointer j from start to second last element:
If arr[j] < pivot, swap arr[i] and arr[j], then increment i.
After traversal, all elements smaller than the pivot are on the left side of index i.
Swap arr[i] with the pivot to place the pivot at its correct position.
Final state: Left of pivot → elements < pivot, Right of pivot → elements ≥ pivot
Note: Elements equal to the pivot may appear on the right side, which contributes to QuickSort being unstable.*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void partition(vector<int>& arr){
    int n = arr.size();
    int pivot = arr[n-1];

    int i = -1;
    for(int j =0; j < n; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[n-1]);
}

int main(){
    vector<int> arr = {5,13,6,9,12,11,8};
    partition(arr);
    for(int num : arr) cout << num << "\n";
    return 0;
}

/*some interesting facts 
- we can easily modify the algorithm to consider the first element[or any other element] as pivot by swapping first and last elements and then using the same code.
- it is easier to understand and implement compared to other paritioning algorithms
- it generally performs slower than hoarer's partition algorithm, especially in cases of large datasets or when the pibot is poorly chosen. as it may require more swaps
- despite its inefficiency it is still sued for its simplicity*/