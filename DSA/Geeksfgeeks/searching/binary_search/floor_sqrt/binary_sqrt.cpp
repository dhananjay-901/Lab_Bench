#include <iostream>
using namespace std;

class Solution{
    public:
    int binary_sqrt(int x){
        int low = 1;
        int high = x;
        int res = 1;
        while(low <=high){
            int mid = low +(high-low)/2;

            if(mid*mid <=x){
                res = mid;
                low = mid+1;
            }

            else{
                high = mid - 1;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    int n = 11;
    cout << s.binary_sqrt(n);
    return 0;
}