//expected approach using binary search
//the minimum distance between cows follows a monotonic property which makes binary search possible. 1. if we can place all cows with a minimum distance d, then placing them with any smaller distance is also possible because allowing smaller gaps gives us more flexibility and space to place cows closer together. 2. on other hand, if we can't place all clows in distance c, then any larger distance also won't work since the increasing the gap makes placement even harder.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
    public:
    bool check(vector<int>& stalls, int k, int dist){
        int cnt = 1;
        int prev = stalls[0];
        for(int i=1; i<stalls.size();i++){
            if(stalls[i]-prev >=dist){
                prev = stalls[i];
                cnt++;
            }
        }
        return (cnt>=k);
    }

    int aggressivecows(vector<int>& stalls, int k){
        sort(stalls.begin(), stalls.end());
        int res = 0;

        int lo = 1;
        int high = stalls.back() - stalls[0];
        while(lo<=high){
            int mid = lo + (high - lo)/2;

            if(check(stalls, k, mid)){
                res = mid;
                lo = mid + 1;
            }else{
                high = mid - 1;
            }
        }

        return res;
    }
};

int main(void){
    Solution s;
    vector<int> stalls = {1, 2, 4, 8, 9}; 
    int k = 3;
    int ans= s.aggressivecows(stalls, k);
    cout << ans;
    return 0;
}