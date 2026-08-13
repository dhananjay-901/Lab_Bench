//If an element is smaller than it's next element then it is guaranteed that at least one peak element will exist on the right side of this element. Conversely if an element is smaller than it's previous element then it is guaranteed that at least one peak element will exist on the left side of this element.

#include <iostream>
#include <vector>

using namespace std;

int peakelement(vector<int>& arr){
  int n = arr.size();

  if(n==1){
    return 0;
  }

  if(arr[0] > arr[1]){
    return 0;
  }

  if(arr[n-1] > arr[n-2]){
    return n-1;
  }

  int low = 1, high = n-2;

  while(low<=high){
    int mid = low + (high-low)/2;

    if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]){
      return mid;
    }

    if(arr[mid] < arr[mid+1]){
      low = mid + 1;
    }

    else{
      high = mid - 1;
    }
  }
  return 0;
}

int main(){
  vector<int> arr = {1,2,4,5,7,8,3};
  cout << peakelement(arr);
  return 0;
}
