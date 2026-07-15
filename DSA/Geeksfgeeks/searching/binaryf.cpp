#include <iostream>
#include <vector>
using namespace std;
//recursive algorithm
class Solution{
    public:
    int binary_search(vector<int>& arr, int low, int high, int x){
        if(high>=low){
            int mid = low + (high-low)/2;
            if (arr[mid]==x){
                return mid;
            }
            if(arr[mid]>x){
                binary_search(arr, low, mid-1,x);
            }
            return binary_search(arr, mid+1, high,x);
        }
    return -1;   
    }
};

int main(){
    vector<int> arr = {1,2,4,7,3,8,5};
    int low = 0;
    int high = arr.size()-1;
    int x = 8;
    Solution s;
    cout << s.binary_search(arr, low, high, x) << "\n";
    return 0;
}