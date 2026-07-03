#include <iostream>
#include <vector>
using namespace std;
/*
the main idea of this approach is to count the number of inversions in an array by using nested loops, checking every possible pair of elements and couting how many such pairs satisfy the inversion condition. the outer loop starts from the first element and goes up to the second to last element and for each i the inner loop runs from the nest element [i+1] to the end of the array. this ensures that all pairs [i,j] where i <j are checked. inside the inner loop, it checks if arr[i]>arr[j] if so it means there is an inversion and the invcount is increamented.
*/
int inversioncount(vector<int>& arr){
    int n = arr.size();
    int invcount = 0;

    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j<n;j++){
            if(arr[i]>arr[j]){
                invcount++;
            }
        }
    }

    return invcount;
}

int main(void){
    vector<int> arr = {4,3,2,1};
    cout << inversioncount(arr) << "\n";
    return 0;
}