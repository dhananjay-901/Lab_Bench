//given a array arr[] where no two adjacent elements are same, find the index of a peak element. an element is considered to be a peak element if it is strictly greater than its adjacent elements. if there are multiple peak elements, return the index of any one of them

#include <vector>
#include <iostream>

using namespace std;

int peakelement(vector<int>& arr){
  int n = arr.size();
  for(int i=0;i<n;i++){
    bool left = true;
    bool right = true;

    if(i>0 && arr[i] <= arr[i-1]){
      left = false;
    }
    if(i<n-1 && arr[i] <= arr[i+1]){
      right = false;
    }
    if(left && right){
      return i;
    }
  }
  return 0;
}

int main(){
  vector<int> arr = {1,2,4,5,7,8,3};
  cout << peakelement(arr);
  return 0;
}
