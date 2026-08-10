//linear search algorithm
//given an array arr[] of n integers and an integers element x, find the whether element x is present in the array return the index of the first occurence of x in the array or -1 if it doesn't exist

#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& arr, int x){
  for(int i=0;i<arr.size();i++){
    if(arr[i] == x){
      return i;
    }
  }
  return -1;
}

int main(){
  vector<int> arr = {2,3,4,10,40};
  int x = 10;
  int res = search(arr, x);
  if(res == -1) cout << "element is not present in the array";
  else cout << "element is present at index" << res;
  return 0;
}


//applications of lienar search algorithm  - unsorted lists when we have unsorted array or list linear seach is most commonly used to find any element in the condition. small data sets linear search is preffered over binary search when we have small data sets with . searching linked lists - in linked lists implementation linear search is commonly used to find elements within the list. each node is checked sequentially until the desired element in found. simple implementation linear search is much easier to understand and implement as compared to binary search or ternary search
