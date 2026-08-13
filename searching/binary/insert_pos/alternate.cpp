//the idea is to refine the traditional binary search by ensuring that we always land on the first position where the target could be inserted unlike the previous approach here we eliminate elements from that right by setting right = mid instead of right = mid-1 ensuring left never skips a potential insert position

#include <iostream>
#include <vector>
using namespace std;

int searchinsertk(vector<int> arr, int k){
  int left = 0, right = arr.size()-1;
  while (left<right){
    int mid = left + (right - left)/2;

    if(arr[mid] < k){
      left = mid + 1;
    }else{
      right = mid;
    }
  }
  return (arr[left] < k) ? left+1 : left;
}

int main(){
  vector<int> arr = {1,3,5,6};
  int k = 5;
  cout << searchinsertk(arr, k) << endl;
  return 0;
}
