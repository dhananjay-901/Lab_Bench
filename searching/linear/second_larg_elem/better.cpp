//the approach is to traverse the array twice. in the first traversal, find the maximum element. in the second traversal find the maximum element ignoring the one we found in the first traversal
#include <iostream>
#include <vector>
using namespace std;

int getsecondlargest(vector<int>& arr){
  int n = arr.size();
  int largest = -1, secondlargest = -1;

  for(int i=0;i<n;i++){
    if(arr[i] > largest) largest = arr[i];
  }

  for(int i=0;i<n;i++){
    if(arr[i] > secondlargest && arr[i] != largest){
      secondlargest = arr[i];
    }
  }
  return secondlargest;
}
int main(){
  vector<int> arr = {12,35,1,10,34,1};
  cout << getsecondlargest(arr);
  return 0;
}
