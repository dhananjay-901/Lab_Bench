#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//naive approach is to use iterative methods to traverse through each element
//but in expected or alternate methods we will be lowering our memory and runtime usage
class Solution{
    public:
    int count(vector<int>& arr, int x){
        int l = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int r = upper_bound(arr.begin(), arr.end(), x) - arr.begin();

        return r-l;

    }
};

int main(){
    Solution s;
    vector<int> arr = {1, 2, 2, 2, 2, 3, 4, 7, 8, 8};
    int target = 2;
    cout << s.count(arr, target) << "\n";
    return 0;
}