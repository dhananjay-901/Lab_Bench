//given a sorted array arr[] and an integer target find the number of occurences of target in given array
//the idea is to traverse the array and for each element, check if it is equal to the target. if you find any element equal to target increment the value of counter variable

#include <iostream>
#include <vector>

using namespace std;

int countfreq(vector<int>& arr, int target){
  int res = 0;
  for(int i=0;i<arr.size();i++){
    if(arr[i] == target) res++;
  }
  return res;
}

int main(){
  vector<int> arr = {1,1,2,2,2,2,3};
  int target = 2;
  cout << countfreq(arr, target);
  return 0;
}
