#include <iostream>
using namespace std;

int search(int arr[], int n, int x){
    for(int i=0; i<n; i++){
        if(x==arr[i]){
            cout<<"found the element";
        }
    }
    return 0;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 5;
    search(arr, n, x);
    return 0;
}