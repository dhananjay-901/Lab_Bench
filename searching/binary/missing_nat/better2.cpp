//in this approach we will create function to find the missing number using the sum of natural numbers formula we will calculate the total sum of the first n natural numbers using formula n*n(n+1)/2 now we calculate sum of all elements in given array. subtract the total sum of all elements in given array and return the missing number

#include <vector>
#include <iostream>
using namespace std;

int missingnumber(vector<int>& arr){
  int n = arr.size()+1;
  int totalsum = n * (n+1)/2;

  int arraysum = 0;
  for(int num : arr){
    arraysum+=num;
  }

  int missingnumber = totalsum - arraysum;
  return missingnumber;
}

int main(){
  vector<int> arr = {1,2,3,4,6,7,8,9};
  cout << missingnumber(arr);
  return 0;
}
