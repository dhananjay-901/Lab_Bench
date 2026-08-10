//fibonacci search - given a sorted array arr[] of size n and integer x. your task is to check if the integer x is present in the array arr[] or not. return idnex of x if it is present in array else return -1.

//the idea is to first find the smallest fibonacci number that is greater than or equal to the length of the given array. let the found fibonacci number be fib. we use (m-2)th fibonacci number as the index. let(m-2) fibonaccci number be i, we compare arr[i] with x. if x is same, we return i. else if x is greater we recur for subarray after i, else we recur for subarray before i

#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& arr, int x){
    int n = arr.size();

    int a = 0, b = 1, c = 1;

    while(c<n){
        a=b;
        b=c;
        c=a+b;
    }

    int offset = -1;

    while(c>1){
        int i = min(offset+a, n-1);
        if(arr[i] < x){
            c=b;
            b=a;
            a=c-b;
            offset = i;
        }

        else if(arr[i] > x){
            c=a;
            b=b-a;
            a = c-b;
        }

        else return i;
    }

    if(b && arr[offset + 1] == x) return offset + 1;
    return -1;
}

int main(){
    vector<int> arr = {2,3,4,10,40};
    int x = 10;
    cout << search(arr, x);
    return 0;
}
