#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
    int count(vector<int>& arr){
        int n = arr.size();
        int ans = 0;
        int low = 0, high = n-1;

        while (low<=high){
            int mid = (low + high)/2;

            if(arr[mid]==0){
                high = mid - 1;
            }
            else if(mid == n-1 || arr[mid+1]!=1){
                return mid+1;
            }
            else{
                low = mid + 1; 
            }
        }
        return 0;
    }
};

int main(){
    vector<int> arr = { 1, 1, 1, 1, 0, 0, 0 };
    Solution s;
    cout << s.count(arr);
    return 0;

}