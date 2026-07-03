//Advanced Quick Sort (Hybrid Algorithm)
/*Prerequisites: Insertion Sort, Quick Sort, Selection Sort
In this article, a Hybrid algorithm with the combination of quick sort and insertion sort is implemented. As the name suggests, the Hybrid algorithm combines more than one algorithm. Why Hybrid algorithm: Quicksort algorithm is efficient if the size of the input is very large. But, insertion sort is more efficient than quick sort in case of small arrays as the number of comparisons and swaps are less compared to quicksort. So we combine the two algorithms to sort efficiently using both approaches. Note: Selectionsort algorithm can also be used to combine with quicksort. Though the time complexity is of O(N2), these algorithms prove to be efficient in this case because these are used only when the size of the array is less than a threshold value(10 in this article).*/

//approach - the idea is to use recursion and continously find the size of the array, if the size is greater than the threshold value(10), then the quicksort function is called for that portion of th array, else insertion sort is called.
// C++ implementation of the above approach 

#include<bits/stdc++.h>
using namespace std;
void insertion_sort(int arr[], int low, int n) 
  {
    for(int i=low+1;i<n+1;i++)
    {
      int val = arr[i] ;
      int j = i ;
    while (j>low && arr[j-1]>val)
      {
        arr[j]= arr[j-1] ;
      j-= 1;
    }
    arr[j]= val ;
    } 

  }
int partition(int arr[], int low, int high)
{
  int pivot = arr[high] ;
  int i ,j;
  i = low;
  j = low;
  for (int i = low; i < high; i++)
     {
      if(arr[i]<pivot)
      {
        int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      j += 1;
      }
    }
  
    int temp = arr[j];
    arr[j] = arr[high];
    arr[high] = temp;

  return j; 
  }
void quick_sort(int arr[], int low,int high)
{
  if (low < high)
  { 
    int pivot = partition(arr, low, high); 
    quick_sort(arr, low, pivot-1) ;
    quick_sort(arr, pivot + 1, high) ;
  }
}
void hybrid_quick_sort(int arr[], int low, int high)
{
  while (low < high) 
    {
    if (high-low + 1 < 10)
      {
        insertion_sort(arr, low, high);
      break;
    }

    else  
        {
          int pivot = partition(arr, low, high) ;
      if (pivot-low<high-pivot)
        {
          hybrid_quick_sort(arr, low, pivot - 1); 
        low = pivot + 1;
      }
      else
        {          
        hybrid_quick_sort(arr, pivot + 1, high);
        high = pivot-1;
        }
     }
   }
}
int main()
{
 int  arr[21] = { 24, 97, 40, 67, 88, 85, 15, 
  66, 53, 44, 26, 48, 16, 52, 
  45, 23, 90, 18, 49, 80, 23 };
hybrid_quick_sort(arr, 0, 20);
  for(int i = 0; i < 21; i++)
    cout << arr[i] << ", ";
}