#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
    public:
    int binarySearch(vector<int>& arr, int k){
        int low = 0;
        int high = (int)arr.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if (arr[mid]==k){
                return mid;
            }
            if(arr[mid]<k){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return -1;
    }
};

int main(){
    vector<int> arr = {5,2,1,8,9,4,6};
    int k = 4;
    sort(arr.begin(), arr.end());
    Solution s;
    cout << s.binarySearch(arr, k) << "\n";
    return 0;
}