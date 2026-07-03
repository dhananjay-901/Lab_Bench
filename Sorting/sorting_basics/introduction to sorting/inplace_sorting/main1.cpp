//a not in place implementation of reversing an array implementation

#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

void reversearray(int arr[], int n){
    int rev[n];
    for(int i=0;i<n;i++){
        rev[n-i-1] = arr[i];
    }
    for(int i=0;i<n;i++){
        arr[i] = rev[i];
    }
}

void printarray(int arr[], int size){
    for(int i=0; i<size;i++){
        cout << arr[i] << "\n";
    }
}

int main(){
    int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    printarray(arr, n);
    reversearray(arr, n);
    cout << "Reversed array is" << endl;
    printarray(arr, n);
    return 0;
}