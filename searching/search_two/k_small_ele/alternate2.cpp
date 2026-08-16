//the main idea is to use counting sort's frequency counts to track how many elements are smaller or equal to each value, and then directly identify then kth smallest element from these cumulative counts without fully sorting the array

#include <iostream>
#include <vector>

using namespace std;

int kthsmallest(vector<int>& arr, int k){
  int maxelement = arr[0];
  for(int i=1;i<arr.size(); i++){
    if(arr[i] > maxelement){
      maxelement = arr[i];
    }
  }

  vector<int> freq(maxelement + 1, 0);
  for(int i=0;i<arr.size();i++){
    freq[arr[i]]++;
  }

  int count = 0;
  for(int i=0;i<=maxelement;i++){
    if(freq[i]!=0){
      count+=freq[i];
      if(count>=k){
        return i;
      }
    }
  }
  return -1;
}

int main(){
  vector<int> arr = {10,5,4,3,48,6,2,33,53,10};
  int k = 4;
  cout << kthsmallest(arr, k);
  return 0;
}
