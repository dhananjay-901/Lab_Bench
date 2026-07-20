//the idea is to use an array to makr alive people. intially all people are alive. starting from the first person we count k alive persons in the circle skipping those already eliminated. when we reach k th alive person we mark them as dead
#include <iostream>
#include <vector>
using namespace std;

int josephus(int n, int k){
    k--;
    int arr[n];

    for(int i=0;i<n;i++){
        arr[i] = 1;
    }
    int cnt = 0, cut = 0, num =1;
    while(cnt < (n-1)){
        while(num <= k){
            cut++;
            cut = cut%n;
            if(arr[cut]==1){
                num++;
            }
        }
        num =1;
        arr[cut] = 0;
        cnt++;
        cut++;
        cut =  cut%n;
        while(arr[cut]==0){
            cut++;
            cut = cut%n;
        }
    }
    return cut + 1; 
}

int main(){
    int n=7,k=3;
    cout << josephus(n, k);
    return 0;
}