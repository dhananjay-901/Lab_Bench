#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
    public:
    vector<int> find(vector<int> arr, int x){
        int n = arr.size();
        int first = -1, last = -1;
        for(int i = 0; i < n; ++i){
            if(arr[i] == x){
                if(first == -1) first = i;
                last = i;
            }
        }
        return {first, last};
    }
};

int main(){
    Solution s;
    vector<int> arr = {1,2,3,4,5,6,7,7,8,12,2,4,123,4,31,2,3,6,2,7,36,7,4};
    int k = 2;
    vector<int> result = s.find(arr, k);
    cout << result[0] << " " << result[1];
    return 0;
}