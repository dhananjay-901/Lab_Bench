//the idea is similar to the iterative approach. here the traversal of the array is done recursively instead of an iterative loop.

#include <iostream>
#include <vector>
using namespace std;

int findmax(vector<int>& arr, int i){
  if(i==arr.size()-1){
    return arr[i];
  }

  int recmax = findmax(arr, i+1);
  return max(recmax, arr[i]);
}

int largest(vector<int>& arr){
  return findmax(arr,0);
}

int main(){
  vector<int> arr = {20,10,20,4,100};
  cout << largest(arr);
  return 0;
}
