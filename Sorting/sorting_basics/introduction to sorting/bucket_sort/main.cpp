/*bucket sort is a sorting technique that involves dividing elements into various groups, or buckets. these buckets are formed by uniformly distributing the elements. once the elements are divided into buckets, they can be sorted using any other sorting algorithm. finally the sorted elements are gathered together in an ordered fashion Works well when the input array elements are uniformly distributed across a range. A stable algorithm because we use Insertion Sort (which is stable) to sort the individual buckets.*/

/*Worst Case Time Complexity: O(n2) The worst case happens when one bucket gets all the elements. In this case, we will be running insertion sort on all items which will make the time complexity as O(n2). We can reduce the worst case time complexity to O(n Log n) by using a O(n Log n) algorithm like Merge Sort or Heap Sort to sort the individual buckets, but that will improve the algorithm time for cases when buckets have small number of items as insertion sort works better for small arrays.

Best Case Time Complexity : O(n + k) The best case happens when every bucket gets equal number of elements. In this case every call to insertion sort will take constant time as the number of items in every bucket would be constant (Assuming that k is linearly proportional to n).*/
#include <iostream>
#include <vector>
using namespace std;

void insertionsort(vector<float>& bucket){
    for(int i=1;i<bucket.size();++i){
        float key = bucket[i];
        int j = i-1;
        while(j>=0 && bucket[j] > key){
            bucket[j+1] = bucket[j];
            j--;
        }
        bucket[j+1] = key;
    }
}

void bucketsort(float arr[], int n){
    vector<float> b[n];
    for(int i=0;i<n;i++){
        int bi = n * arr[i];
        b[bi].push_back(arr[i]);
    }

    for(int i =0 ;i<n;i++){
        insertionsort(b[i]);
    }

    int index = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<b[i].size();j++){
            arr[index++] = b[i][j];
        }
    }
}
int main(){
    float arr[] = {0.897, 0.565, 0.6565, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr)/sizeof(arr[0]);
    bucketsort(arr, n);

    for(float num:arr) cout << num << "\n";
    return 0;
}