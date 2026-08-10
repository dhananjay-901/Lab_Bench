//given an arr[] of elements of size n, return the largest element given in the array
//traverse the entire array and keep track of the largest element encountered. update the maximum value whenever a larger element is found, and after scanning all elements, the stored valye represents the largest element in the array

#include <iostream>
#include <vector>
using namespace std;

int largest(vector<int>& arr){
  int max = arr[0];

  for(int i=1;i<arr.size();i++){
    if(arr[i] > max) max = arr[i];
  }
  return max;
}

int main(){
  vector<int> arr = {20,10,20,4,100};
  cout << largest(arr);
  return 0;
}
