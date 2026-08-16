//given an array arr[] where each element denotes the number of bananas in a pile and an integer k representing the total number of hours available. in one hour up to x bananas can be eaten from a single pile. if a pile contains fewer than x bananas the entire pile is consumde in one hour. it is guaranteed that the number of piles is less than or equal to k. determine the minimum value of x such that all piles can be completed within k hours

//the idea is to try every possible eating speed from 1 to max(arr) and for each speed calculate the total time required to finish all piles. for a given speed x the time to finish a pile is (pile + x - 1) // x and we sum this over all piles. the smallest speed for which the total time is less than or equal to k is the required answer

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int kokofat(vector<int>& arr, int k){
  int mx = *max_element(arr.begin(), arr.end());

  for(int speed = 1; speed<=mx; speed++){
    long long reqtime = 0;

    for(int i=0;i<arr.size();i++){
      reqtime+= (arr[i] + speed - 1)/ speed;
    }

    if(reqtime <= k){
      return speed;
    }
  }
  return mx;
}

int main(){
  vector<int> arr = {5,10,3};
  int k = 4;

  int minspeed = kokofat(arr, k);
  cout << minspeed << endl;
  return 0;
}
