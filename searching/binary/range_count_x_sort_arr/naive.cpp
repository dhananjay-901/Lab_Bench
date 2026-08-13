//given a sorted array arr[] and a list of queries represented as a 2d array queries[][]. each query is a triplet of the form [l,r,x] where l and r are indices in the array and x is the value to search for

#include <iostream>
#include <vector>

using namespace std;

vector<int> countxinrange(vector<int>& arr, vector<vector<int>>& queries){
  vector<int> result;

  for(auto& query : queries){
    int l = query[0];
    int r = query[1];
    int x = query[2];
    int count = 0;

    for(int i=l;i<=r;i++){
      if(arr[i] == x){
        count++;
      }
    }
    result.push_back(count);
  }
  return result;
}

int main(){
  vector<int> arr = {1,2,2,4,5,5,5,8};
  vector<vector<int>> queries = {{0,7,5},{1,2,2},{0,3,7}};

  vector<int> res = countxinrange(arr, queries);
  for(int count : res){
    cout << count << " ";
  }
  cout << endl;
  return 0;
}
