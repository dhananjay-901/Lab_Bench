//first and last occurrence in sorted data structure 

// naive approach
#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
    vector<int> landf(vector<int>& arr, int x){
        int n = arr.size();

        int first = -1, last = -1;

        for(int i=0; i<n;i++){
            if (x!=arr[i]){
                continue;
            }
            if (first == -1){
                first = i;
            }

            last = i;
        }

        vector<int> res = {first, last};
        return res;
    }
};

int main(){
    Solution s;
    vector<int> arr = {1,2,3,4,5,6,7,7,8,12,2,4,123,4,31,2,3,6,2,7,36,7,4};
    int k = 2;
    vector<int> result = s.landf(arr, k);
    cout << result[0] << " " << result[1];
    return 0;
}