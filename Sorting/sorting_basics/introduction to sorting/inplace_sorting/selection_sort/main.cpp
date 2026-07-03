/*Selection Sort is a comparison-based sorting algorithm. It sorts by repeatedly selecting the smallest (or largest) element from the unsorted portion and swapping it with the first unsorted element.

Find the smallest element and swap it with the first element. This way we get the smallest element at its correct position.
Then find the smallest among remaining elements (or second smallest) and swap it with the second element.
We keep doing this until we get all elements moved to correct position.*/

#include <bits/stdc++.h>
using namespace std;

void selectionsort(vector<int>& arr){
    int n = arr.size();
    for(int i=0;i<n-1;++i){
        int min_idx = i;

        for(int j=i+1;j<n;++j){
            if(arr[j]<arr[min_idx]){
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}

void printarray(vector<int>& arr){
    for(int &val:arr){
        cout << val << "\n";
    }
}

int main(){
    vector<int> arr = {64,25,12,22,11};
    printarray(arr);
    selectionsort(arr);
    printarray(arr);
    return 0;
}

/*
Complexity Analysis of Selection Sort
Time Complexity: O(n2) ,as there are two nested loops:

One loop to select an element of Array one by one = O(n)
Another loop to compare that element with every other Array element = O(n)
Therefore overall complexity = O(n) * O(n) = O(n*n) = O(n2)
Auxiliary Space: O(1) as the only extra memory used is for temporary variables.

Advantages of Selection Sort
Easy to understand and implement, making it ideal for teaching basic sorting concepts.
Requires only a constant O(1) extra memory space.
It requires less number of swaps (or memory writes) compared to many other standard algorithms. Only cycle sort beats it in terms of memory writes. Therefore it can be simple algorithm choice when memory writes are costly.
Disadvantages of the Selection Sort
Selection sort has a time complexity of O(n^2) makes it slower compared to algorithms like Quick Sort or Merge Sort.
Does not maintain the relative order of equal elements which means it is not stable.
Applications of Selection Sort
Perfect for teaching fundamental sorting mechanisms and algorithm design.
Suitable for small lists where the overhead of more complex algorithms isn't justified and memory writing is costly as it requires less memory writes compared to other standard sorting algorithms.
Heap Sort algorithm is based on Selection Sort.
*/