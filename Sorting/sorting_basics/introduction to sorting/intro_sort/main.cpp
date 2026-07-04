/*Introsort(Introspective sort) is a comparison based sort that consists of three sorting phases. They are Quicksort, Heapsort, and Insertion sort. Basic concepts of Introsort and the C++ code are available here
The following section shows how the Introsort algorithm is formulated, after reviewing the pros and cons of the respective algorithms. 
Quicksort 
The Quicksort is an efficient sorting algorithm but has the worst-case performance of O(N ^ 2) comparisons with O(N) auxiliary space. This worst-case complexity depends on two phases of the Quicksort algorithm. 
1. Choosing the pivot element 
2. Recursion depth during the course of the algorithm
Heapsort 
Heapsort has O(N log N) worst-case time complexity, which is much better than the worst case of Quicksort. So, is it evident that Heapsort is the best? No, the secret of Quicksort is that it does not swap already elements that are already in order, which is unnecessary, whereas with the Heapsort, even if all of the data is already sorted, the algorithm swaps all of the elements to order the array. Also, by choosing the optimal pivot, the worst-case of O(N ^ 2) can be avoided in quicksort. But, the swapping will pay more time in the case of Heapsort that is unavoidable. Hence, Quicksort outperforms Heapsort.
The best things about Heapsort is that, if the recursion depth becomes too large like (log N), the worst case complexity would be still O(N log N).
 Mergesort 
The Mergesort has the worst case complexity only as O(N log N). Mergesort can work well on any type of data sets irrespective of its size whereas the Quicksort cannot work well with large data sets. But, Mergesort is not in-place whereas Quicksort is in-place, and that plays a vital role in here. Mergesort goes well with LinkedLists whereas Quicksort goes well with arrays. The locality of reference is better with Quicksort, whereas with Mergesort it is bad. So, for conventional purposes, having memory constraints in hand, Quicksort outperforms Mergesort.
 Insertion sort 
The main advantage of the insertion sort is its simplicity. It also exhibits a good performance when dealing with a small list. The insertion sort is an in-place sorting algorithm so the space requirement is minimal. The disadvantage of the insertion sort is that it does not perform as well as the other sorting algorithms when the size of the data gets larger.
 
Here is how Introsort is formulated: 
Choosing the right sorting algorithm depends on the occasion where the sorting algorithm is being used. There are a good number of sorting algorithms in hand already that has pros and cons of its own. So, to get a better sorting algorithm, the solution is to tweak the existing algorithms and produce a new sorting algorithm that works better. There are a lot of hybrid algorithms, that outperforms the general sorting algorithms. One such is the Introsort. The best versions of Quicksort are competitive with both heap sort and merge sort on the vast majority of inputs. Rarely Quicksort has the worst case of O(N ^ 2) running time and O(N) stack usage. Both Heapsort and Mergesort have O(N log N) worst-case running time, together with a stack usage of O(1) for Heapsort and O(log N) for Mergesort respectively. Also, Insertion sort performs better than any of the above algorithms if the data set is small.
Combining all the pros of the sorting algorithms, Introsort behaves based on the data set. 

If the number of elements in the input gets fewer, the Introsort performs Insertion sort for the input.
Having the least number of comparisons(Quicksort) in mind, for splitting the array by finding the pivot element, Quicksort is used. Quoted earlier, the worst case of Quicksort is based on the two phases and here is how we can fix them.
Choosing the pivot element: We can use either of median-of-3 concept or randomized pivot concept or middle as the pivot concept for finding the pivot element
Recursion depth during the course of the algorithm: When the recursion depth gets higher, Introsort uses Heapsort as it has the definite upper bound of O(N log N).
How does depthLimit work? 
depthLimit represents maximum depth for recursion. It is typically chosen as log of length of input array (please refer below implementation). The idea is to ensure that the worst case time complexity remains O(N log N). Note that the worst-case time complexity of HeapSort is O(N log N).

Why is Mergesort not used? 
As the arrays are being dealt with the in-place concept where Quicksort outperforms Mergesort, we are not using Mergesort.

Can Introsort be applied everywhere?  

If the data won't fit in an array, Introsort cannot be used.
Furthermore, like Quicksort and Heapsort, Introsort is not stable. When a stable sort is needed, Introsort cannot be applied.
Is Introsort the only hybrid sorting algorithm? 
No. There are other hybrid sorting algorithms like Hybrid Mergesort, Tim sort, Insertion-Merge hybrid.
Comparison of Heapsort, Insertion sort, Quicksort, Introsort while sorting 6000 elements(in milliseconds). */

#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

void swapvalue(int* a, int* b){
    swap(*a, *b);
}

void insertionsort(int arr[], int* begin, int* end){
    int left = begin - arr;
    int right = end - arr;

    for(int i = left + 1; i <= right; ++i){
        int key = arr[i];
        int j = i - 1;

        while(j >= left && arr[j] > key){
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

int* partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j <= high - 1; ++j){
        if(arr[j] <= pivot){
            ++i;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return arr + i + 1;
}

int* medianofthree(int* a, int* b, int* c){
    if(*a < *b){
        if(*b < *c) return b;
        if(*a < *c) return c;
        return a;
    } else {
        if(*a < *c) return a;
        if(*b < *c) return c;
        return b;
    }
}

void introsortutil(int arr[], int* begin, int* end, int depthlimit){
    if(begin >= end) return;

    int size = static_cast<int>(end - begin + 1);
    if(size < 16){
        insertionsort(arr, begin, end);
        return;
    }

    if(depthlimit == 0){
        make_heap(begin, end + 1);
        sort_heap(begin, end + 1);
        return;
    }

    int* pivot = medianofthree(begin, begin + size / 2, end);
    swapvalue(pivot, end);

    int low = static_cast<int>(begin - arr);
    int high = static_cast<int>(end - arr);
    int* partitionpoint = partition(arr, low, high);

    if(partitionpoint > begin){
        introsortutil(arr, begin, partitionpoint - 1, depthlimit - 1);
    }
    if(partitionpoint < end){
        introsortutil(arr, partitionpoint + 1, end, depthlimit - 1);
    }
}

void introsort(int arr[], int* begin, int* end){
    int n = static_cast<int>(end - begin + 1);
    int depthlimit = static_cast<int>(2 * log2(n));
    introsortutil(arr, begin, end, depthlimit);
}

void printarray(int arr[], int n){
    for(int i = 0; i < n; ++i){
        cout << arr[i] << "\n";
    }
}
int main(){
    int arr[] = { 2,  10, 24, 2,  10, 11, 27, 4,  2,  4, 28, 16, 9,  8,  28, 10, 13, 24, 22, 28, 0,  13, 27, 13, 3,  23, 18, 22, 8,8};
    int n = sizeof(arr)/sizeof(arr[0]);

    introsort(arr, arr,arr+n-1);
    printarray(arr, n);
    return 0;
}