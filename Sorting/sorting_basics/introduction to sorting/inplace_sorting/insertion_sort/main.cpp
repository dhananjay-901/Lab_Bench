/*Insertion sort is a simple sorting algorithm that works by iteratively inserting each element of an unsorted list into its correct position in a sorted portion of the list. It is like sorting playing cards in your hands. You split the cards into two groups: the sorted cards and the unsorted cards. Then, you pick a card from the unsorted group and put it in the right place in the sorted group.

Start with the second element as the first element is assumed to be sorted.
Compare the second element with the first if the second is smaller then swap them.
Move to the third element, compare it with the first two, and put it in its correct position
Repeat until the entire array is sorted.*/

/*for time and space complexity of insertion sort 
refer this
https://www.geeksforgeeks.org/dsa/time-and-space-complexity-of-insertion-sort-algorithm/
*/
#include <iostream>
using namespace std;

void insertionsort(int arr[], int n){
    for(int i=1;i<n;++i){
        int key = arr[i];
        int j = i-1;

        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

void printarray(int arr[], int n){
    for(int i=0;i<n;i++){
        cout << arr[i] << "\n";
    }
}

int main(){
    int arr[] = {12,11,13,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertionsort(arr, n);
    printarray(arr, n);
}