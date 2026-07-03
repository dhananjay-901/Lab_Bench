// this needs 0[n] extra space and is an example of not in place algorithm an in place implementation of reversing an array.

#include <bits/stdc++.h>
using namespace std;

void reversearray(int arr[], int n){
    for(int i=0;i<n/2;i++){
        swap(arr[i], arr[n-i-1]);
    }
}

void printarray(int arr[], int size){
    for(int i=0;i<size;i++){
        cout << arr[i] << "\n";
    }
}

int main(){
    int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    printarray(arr,n);
    reversearray(arr,  n);
    printarray(arr, n);
    return 0;
}