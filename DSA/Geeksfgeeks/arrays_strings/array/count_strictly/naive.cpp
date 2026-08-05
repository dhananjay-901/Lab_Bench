//given a integer array arr[] count the number of subarrays in arr[] that are strictly increasing and have a size of at least 2. a subarray is a contiqous sequence of elements from arr[]. a subarray is strictly increasing if each element is greater than its previous elements

//count all strictly increasing subarrays by starting from each index i and expanding forward. for every starting point, we use another pointer j, to extend the subarray as long as the elements keep increasing. as soon as the increasing order breaks, we stop extending from that starting point and move to the next index.

#include <iostream>
#include <vector>

using namespace std;

int countincreasing(vector<int>& arr){
      int n = arr.size();
      int count = 0;

      for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j-1] >=arr[j]) break;
            count++;
        }
    }
    return count;
}
int main(){
    vector<int> arr = {1,4,5,3,7,9};
    cout << countincreasing(arr) << endl;
    return 0;
}
