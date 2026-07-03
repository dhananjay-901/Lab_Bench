//this is the best way for quick sort

/*Given an array arr[], the task is to partition the array by assuming first element as pivot element.
The partition of an array must satisfy the following two conditions: Elements smaller than pivot element must appear at index less than or equal to partition index. Elements larger than or equal to pivot element must appear at index greater than partition index. Partition index is equal to count of elements, strictly smaller than pivot, minus one. Note: There might me more than one possible partition arrays.*/

//hoare's partition algorithm is an efficient way to parition an array around a pivot. it's based on two pointers that start at opposite ends of the array and move toward each other they find elements that need to swapped

/*Step-by-step explanation of algorithm:
Consider the first element as the pivot and initialise two pointers, i at the start and j at the end of the array. Move i to the right until an element greater than or equal to the pivot is found, and move j to the left until an element less than or equal to the pivot is found. If i points to an element greater than or equal to the pivot and j points to an element less than or equal to the pivot, swap them. Repeat the process, moving i and j toward each other until they meet or cross. When the pointers cross, the partitioning is complete, with elements less than or equal to the pivot on the left and those greater than or equal to the pivot on the right.*/

#include <iostream>
#include <vector>
using namespace std;

void partition(vector<int>& arr){
    int n = arr.size();
    int pivot = arr[0];
    int i = -1, j = n;
    while(true){
        do{
            i++;            
        }while(arr[i] < pivot);

        do{
            j--;
        }while(arr[j] > pivot);

        if(i > j) break;

        swap(arr[i], arr[j]);
    }
}

int main(){
    vector<int> arr = {5,3,8,4,2,7,1,10};
    partition(arr);
    for(int num : arr) cout << num << "\n";
    return 0;
}

/*Some Interesting Facts
Hoare's Partition Algorithm is generally faster than Lomuto's because it performs fewer swaps and makes only one traversal of the array, leading to better time complexity in practice. It works in-place and does not require extra space, unlike the naive partitioning method which uses a temporary array. It can be used to implement a stable version of Quick Sort with the right adjustments, though it is not inherently stable. We can easily modify the algorithm to consider the first element (or any other element) as pivot by swapping first and last elements and then using the same code.*/