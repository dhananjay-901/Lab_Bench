/*Heap Sort is a comparison-based sorting algorithm based on the Binary Heap data structure.

It is an optimized version of selection sort.
The algorithm repeatedly finds the maximum (or minimum) element and swaps it with the last (or first) element.
Using a binary heap allows efficient access to the max (or min) element in O(log n) time instead of O(n).
The process is repeated for the remaining elements until the array is sorted.
Overall, Heap Sort achieves a time complexity of O(n log n).
Heap Sort Algorithm :
First convert the array into a max heap using heapify, Please note that this happens in-place. The array elements are re-arranged to follow heap properties. Then one by one delete the root node of the Max-heap and replace it with the last node and heapify. Repeat this process while size of heap is greater than 1.*/

#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>& arr, int n, int i){
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;

    if(l<n && arr[l]>arr[largest])  largest = l;
    if(r < n && arr[r] > arr[largest]) largest = r;
    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapsort(vector<int>& arr){
    int n = arr.size();
    for(int i = n/2 - 1; i >= 0; --i) heapify(arr, n, i);
    for(int i = n-1;i>0;i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main(){
    vector<int> arr = {9,4,3,8,10,2,5};
    heapsort(arr);
    for(int i=0;i<arr.size();++i){
        cout << arr[i] << "\n";
    }
    return 0;
}

/*Time Complexity: O(n log n)
Auxiliary Space: O(log n), due to the recursive call stack. However, auxiliary space can be O(1) for iterative implementation.

Important points about Heap Sort
An in-place algorithm.
Its typical implementation is not stable but can be made stable (See this)
Typically 2-3 times slower than well-implemented QuickSort. The reason for slowness is a lack of locality of reference.
Advantages of Heap Sort
Efficient Time Complexity: Heap Sort has a guaranteed time complexity of O(n log n) in all cases, making it suitable for large datasets. The log n factor comes from the height of the binary heap, ensuring consistent performance.
Minimal Memory Usage: Heap Sort can work in-place with minimal extra memory. Using an iterative heapify() avoids additional stack space, so apart from storing the array itself, no extra memory is required.
Simplicity: Heap Sort is relatively easy to understand and implement compared to other efficient sorting algorithms, as it relies on the straightforward binary heap structure without advanced concepts like recursion (if iterative heapify is used).
Disadvantages of Heap Sort
Costly: Heap sort is costly as the constants are higher compared to merge sort even if the time complexity is O(n log n) for both.
Unstable: Heap sort is unstable. It might rearrange the relative order.
Inefficient: Heap Sort is not very efficient because of the high constants in the time complexity.*/