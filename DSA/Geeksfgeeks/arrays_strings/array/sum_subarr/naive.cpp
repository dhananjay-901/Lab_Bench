//given an integer arr[] compute the sum of all possible subarrays  of the array. a sub array is a contigous part of the arary
//the main idea of this approach is to iterate over all possible subarrays of the given array using two nested loops. the outer loop selects the starting index of the subarray, while the inner loop extends the subaray to include all possible ending pointers. during this process, a running sum temp is maintaind for each subarray and added to the total result.
#include <iostream>
#include <vector>
using namespace std;

int subarraysum(vector<int>& arr){
    int n = arr.size();
    int result  = 0, temp = 0;

    for(int i=0;i<n;i++){
        temp = 0;
        for(int j=i;j<n;j++){
            temp+=arr[j];
            result +=temp;
        }
    }
    return result;
}

int main(){
    vector<int> arr = {1,4,5,3,2};
    int n = arr.size();
    cout << subarraysum(arr) << endl;
    return 0;
}
