//given a sorted array arr[] of unique integers an integer k and a target value x. return exactly k elements from the array closest to x, excluding x if it exists

//the idea is to use the absolute difference between each element and the target value to measure how close they are. then we apply custom sorting: elements with smaller differences come first, and in case of a tie, the larger element is preffered. we take the k element from get from custom sorted array then return it

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> findkclosest(vector<int>& arr, int k, int x){
  sort(arr.begin(), arr.end(), [x](int a, int b){
    int diffa = abs(a-x);
    int diffb = abs(b-x);

    if(diffa == diffb){
      return a>b;
    }
    return diffa<diffb;
  });

  vector<int> result;
  int count = 0;
  for(int num : arr){
    if(num == x) continue;
    result.push_back(num);
    count++;
    if(count == k) break;
  }
  return result;
}

int main(){
  vector<int> arr = {1,3,4,10,12};
  int k = 2;
  int x = 4;

  vector<int> closest = findkclosest(arr, k, x);
  for(int num : closest){
    cout << num << " ";
  }
  return 0;
}
