//given a sorted array arr[] where every element appears exactly twice except one element that appears only once, find that single element. the idea behind this approach is to check every adjacent element in order to find if there exists its pair or not as the array is sorted

#include <iostream>
#include <vector>
using namespace std;

int single(vector<int>& arr){
  int n = arr.size();
  for(int i=0;i<n-1;i+=2){
    if(arr[i]!=arr[i+1]){
      return arr[i];
    }
  }
  return arr[n-1];
}

int main(){
  vector<int> arr = {1,1,2,2,3,4,4};
  cout << single(arr);
  return 0;
}
