/*Cycle Sort is an in-place, unstable, comparison-based sorting algorithm that is optimal in terms of the minimum number of memory writes.

The idea is to divide the array into cycles, where each cycle consists of elements that belong to each other’s correct positions, and then rotate these cycles to place all elements correctly.
In Cycle Sort, each element is written at most once to its correct position, making it useful in situations where write operations are costly.*/

/*the main idea is simple: for every element count how many elements are smaller than it. this count gives it correct position in the sorted array. if the element is not already as its correct position place it there. while placing another element gets displaced - repeat the same process for that element. this continues until we come back to the starting point, forming a cycle*/

#include <bits/stdc++.h>
#include <utility>
using namespace std;

void cyclesort(vector<int>& arr){
    int n = arr.size();
    for(int cycle_start = 0; cycle_start <= n-2; cycle_start++){
        int item = arr[cycle_start];
        int pos = cycle_start;
        for(int i = cycle_start + 1; i < n;i++) if(arr[i]<item) pos ++;

        if(pos == cycle_start) continue;
        while(item == arr[pos]) pos +=1;
        if(pos !=cycle_start){
            swap(item, arr[pos]);
        }
        while(pos!=cycle_start){
            pos = cycle_start;
            for(int i = cycle_start + 1; i < n;i++) if(arr[i] < item) pos+=1;

            while(item == arr[pos]) pos +=1;

            if(item != arr[pos]){
                swap(item, arr[pos]);
            }
        }
    }
}

int main(){
    vector<int> arr = {3,5,2,1,4};
    int n = arr.size();
    cyclesort(arr);

    for(int i =0;i<n;i++){
        cout << arr[i] << "\n";
    }
    return 0;
}