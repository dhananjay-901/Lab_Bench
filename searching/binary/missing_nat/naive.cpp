//given a sorted array arr[] of n-1 integers, these integers are in the rang of 1to n. there are no duplicates in the array. one of the arrays is missing in the array. find the missing integers
//the idea is to use two nested loops, where the outer one iterate from 1 to n and inner one iterate for each of the array arr[] elements, if the value in outer loop in not found in array arr[] return value else iterate to the next value

#include <iostream>
#include <vector>

using namespace std;

int missingnumber(vector<int>& arr){
  int n = arr.size()+1;

  for(int i=1;i<=n;i++){
    bool found = false;
    for(int j=0;j<n-1;j++){
      if(arr[j]==i){
        found = true;
        break;
      }
    }

    if(!found) return i;
  }
  return -1;
}

int main(){
  vector<int> arr = {1,2,3,4,5,6,7,8};
  cout << missingnumber(arr) << endl;
  return 0;
}
