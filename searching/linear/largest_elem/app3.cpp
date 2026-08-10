#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int largest(vector<int>& arr){
  return *max_element(arr.begin(), arr.end());
}

int main(){
  vector<int> arr = {20,10,20,4,100};
  cout << largest(arr);
  return 0;
}
