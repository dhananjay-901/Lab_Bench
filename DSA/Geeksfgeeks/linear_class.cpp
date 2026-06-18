#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
    int search(vector<int>& arr, int x){
        int n = arr.size();
        for(int i=0;i<n;i++){
            if(x==arr[i]){
                return i;
            }
        }                
        return -1;
    }
};

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    int x = 8;
    Solution s;
    cout << s.search(arr, x) << "\n";
    return 0;
}