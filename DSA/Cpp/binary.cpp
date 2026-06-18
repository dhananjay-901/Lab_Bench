#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
    bool binarySearch(vector<int>& arr, int k){
        int low = 0;
        int high = arr.size()-1;
        int mid = low + (high-low)/2;
        while(low<=high){
            if (arr[mid]==k){
                return k;
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
    Solution s;
    cout << s.binarySearch(arr, k) << "\n";
    return 0;
}