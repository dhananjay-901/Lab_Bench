//minimum in a sorted and rotated array
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
//naive approach
class Solution{
    public:
    int min_num(vector<int>& arr){
        int res = arr[0];
        int n = arr.size();
        for(int i = 1; i<n; i++){
            res = min(res, arr[i]);
        }
        return res;
    }
};  

int main(){
    Solution s;
    vector<int> arr = {9,2,3,4,5,6,6,2,23,3,5,8,0};
    cout << s.min_num(arr) << "\n";
    return 0;
}