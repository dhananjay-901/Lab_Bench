/*do refer these links
https://www.geeksforgeeks.org/dsa/time-and-space-complexity-analysis-of-quick-sort/
https://www.geeksforgeeks.org/dsa/tail-recursion/
https://www.geeksforgeeks.org/dsa/quicksort-tail-call-optimization-reducing-worst-case-space-log-n/
https://www.geeksforgeeks.org/dsa/application-and-uses-of-quicksort/
*/

/*QuickSort is a sorting algorithm based on the Divide and Conquer that picks an element as a pivot and partitions the given array around the picked pivot by placing the pivot in its correct position in the sorted array. .

There are mainly three steps in the algorithm:

Choose a Pivot: Select an element from the array as the pivot. The choice of pivot can vary (e.g., first element, last element, random element, or median).
Partition the Array: Re arrange the array around the pivot. After partitioning, all elements smaller than the pivot will be on its left, and all elements greater than the pivot will be on its right.
Recursively Call: Recursively apply the same process to the two partitioned sub-arrays.
Base Case: The recursion stops when there is only one element left in the sub-array, as a single element is already sorted.

choice of pivot - there are many different choices for picking pivots
- always picks the first[or last] element as a pivot the implementation picks the last element as a pivot. the problem with this approach is it ends up in the worst case when the array is already sorted.
- picks a random element as a pivot. this is preferred approach because it doesn't have a pattern for which the worst case happens.
- pick the median element is pivot. this is an ideal approach in terms of time complexity as we can find median in linear time and the partition function will always divide the input array into two halves. but it takes more time on average as median finding has high constants

partition algorithm
the key process in quicksort is a partition(). there are three common algorithms to partition. all these algorithms have o(n) time complexity.
1. naive paritition - here we create copy of the first arrayy. first put all smaller element and then all greater. finally we copy the temporary array back to original array. this requiers O[n] extra space
2. lamuto partition - we have used this partition in this article. this is a simple algorithm, we keep track of index of smaller elements and keep swapping.
3. hoare's partition - this is the fastest of all. here traverse array from both sides and keep swapping greater element on elft with smaller on right while the array is not partitioned*/

//working of lomuto partition algorithm
//the logic is simple, we start from the leftmost element and keep track of the index of smaller[or equal] elements as i. whicl traversing if we find a smaller element we swap the current element with arr[i] otherwise we ignore the current element.
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high){
    int pivot =  arr[high];
    int i = low - 1;
    for(int j = low; j<=high - 1; j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }

    swap(arr[i+1], arr[high]);
    return i+1;
}

void quicksort(vector<int>& arr, int low, int high){
    if(low < high){
        int pi = partition(arr,  low, high);
        quicksort(arr,  low, pi-1);
        quicksort(arr,  pi + 1, high);
    }
}

int main(){
    vector<int> arr = {10,7,8,9,1,5};
    int n = arr.size();
    quicksort(arr,0,n-1);
    for(int num : arr) cout << num << "\n";
    return 0;
}

/*Complexity Analysis of Quick Sort
Time Complexity:

Best Case: (Ω(n log n)), Occurs when the pivot element divides the array into two equal halves.
Average Case (θ(n log n)), On average, the pivot divides the array into two parts, but not necessarily equal.
Worst Case: (O(n²)), Occurs when the smallest or largest element is always chosen as the pivot (e.g., sorted arrays).
Auxiliary Space:

Worst-case scenario: O(n) due to unbalanced partitioning leading to a skewed recursion tree requiring a call stack of size O(n).
Best-case scenario: O(log n) as a result of balanced partitioning leading to a balanced recursion tree with a call stack of size O(log n).
Please refer Time and Space Complexity Analysis of Quick Sort for more details.

Advantages of Quick Sort
It is a divide-and-conquer algorithm that makes it easier to solve problems.
It is efficient on large data sets.
It has a low overhead, as it only requires a small amount of memory to function.
It is Cache Friendly as we work on the same array to sort and do not copy data to any auxiliary array.
Fastest general purpose algorithm for large data when stability is not required.
It is tail recursive and hence all the tail call optimization can be done.
Disadvantages of Quick Sort
It has a worst-case time complexity of O(n2), which occurs when the pivot is chosen poorly.
It is not a good choice for small data sets.
It is not a stable sort, meaning that if two elements have the same key, their relative order will not be preserved in the sorted output in case of quick sort, because here we are swapping elements according to the pivot's position (without considering their original positions).
Applications of Quick Sort
Sorting large datasets efficiently in memory.
Used in library sort functions (like C++ std::sort and Java Arrays.sort for primitives).
Arranging records in databases for faster searching.
Preprocessing step in algorithms requiring sorted input (e.g., binary search, two-pointer techniques).
Finding the kth smallest/largest element using Quickselect (a variant of quicksort).
Sorting arrays of objects based on multiple keys (custom comparators).
Data compression algorithms (like Huffman coding preprocessing).
Graphics and computational geometry (e.g., convex hull algorithms).*/