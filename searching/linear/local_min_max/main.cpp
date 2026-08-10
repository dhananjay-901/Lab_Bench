//given a integer arr[] representing a sequence of elevations return an array that includes the first and last elements of the array. every element where the trend of the sequence changes that is, where the direction of change switches from increasing to decreasing or form decreasing to increasing.

//approach - the idea is to follow the changes in elevation in elevation as we move through the array. we start by adding the first point. then for each point, we check if it forms a peak or valley- that means the direction of the trail is changing there. if it does we include it. at the end we add the last point if it's not already there. this way we keep only the important turning points and ignore the flat or straight parts

#include <iostream>
#include <vector>
using namespace std;

vector<int> extrapoints(vector<int>& arr){
  int n = arr.size();
  vector<int> ans;

  if(n==0) return ans;

  ans.push_back(arr[0]);
  for(int i=1;i<n-1;i++){
    if(arr[i] > ans.back() && arr[i] > arr[i+1]) ans.push_back(arr[i]);

    else if(ans.back() > arr[i] && arr[i] < arr[i+1]) ans.push_back(arr[i]);
  }

  if(ans.back() != arr[n-1]){
    ans.push_back(arr[n-1]);
  }
  return ans;
}

int main(){
  vector<int> arr = {6,4,2,-2,5,3,2,2,-1,-1,4};
  vector<int> result = extrapoints(arr);
  for(int i=0;i<result.size();i++){
    cout << result[i] << " ";
  }
  return 0;
}
