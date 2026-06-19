#include <iostream>
#include <vector>
using namespace std;
//expected approach using binary search

class Solution{
public:
    int findmin(vector<int>& arr){
        int low = 0, high = arr.size()-1;

        while(low<high){
            if(arr[low]<arr[high]){
                return arr[low];
            }

            int mid = low + (high - low)/2;
            if(arr[mid]>arr[high]){
                low = mid+1;
            }else{
                high = mid;
            }
        }
        return arr[low];
    }
};

int main(){
    Solution s;
    vector<int> arr = {9,2,2,12,44,7,2,1,56,8,2,4,4,5,6};
    cout << s.findmin(arr) << "\n";
    return 0;

}