//given a sorted and rotated array determine if a given key exists in it return true if found otherwise false

//a simple approach is to iterate through the array and check for each element if it matches the target then return the index otherwise return -1 to know more about the implementation

#include <iostream>
#include <vector>
using namespace std;

bool search(vector<int>& arr, int key){
  for(int i=0;i<arr.size();i++){
    if(arr[i] == key){
      return true;
    }
  }
  return false;
}

int main(){
  vector<int> arr = {3,3,3,1,2,3};
  int key = 3;
  bool found = search(arr, key);
  cout << (found ? "true" : "false") << endl;
  return 0;
}
