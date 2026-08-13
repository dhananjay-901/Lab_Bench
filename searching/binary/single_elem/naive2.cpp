//the idea behind this approach is to use bitwise xor between the pair of elements as xor of two same numbers is always equal to 0

#include <iostream>
#include <vector>
using namespace std;

int single(vector<int>& arr){
  int XOR = 0;
  for(int i=0;i<arr.size();i++){
    XOR^=arr[i];
  }
  return XOR;
}

int main(){
  vector<int> arr = {1,1,2,2,3,4,4};
  cout << single(arr) << " \n";
  return 0;
}
