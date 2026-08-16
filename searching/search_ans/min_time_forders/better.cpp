//the idea is to use binary search on the time to find the minimum time required to produce at least n donuts. for any given time, we calculate how many donuts each chef can make by summing the terms of an arithmetic progression where each chef takes r, 2r, 3r seconds per donut. with r being the chef's rank. the total number of donuts made is the sum of such aps across all chefs. if the total meets or exceeds n, we try to minimuse the time further otherwise we increase it. this combination of ap sum logic and binary search helps efficiently reach the answer

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int donutsbychef(int t, int r){
    double D = 1.0 + 8.0  * t/r;
    return int((-1.0 + sqrt(D)) / 2.0);
}

bool canmake(vector<int>& ranks, int n, int t){
    int total = 0;
    for(int r : ranks){
        total+=donutsbychef(t,r);
        if(total>=n) return true;
    }
    return false;
}

int mintime(vector<int>& ranks, int n){
    int rmin = *min_element(ranks.begin(), ranks.end());
    int high = rmin * n * (n+1) / 2;
    int low = 0, ans = high;

    while(low <= high){
        int mid = low + (high - low) / 2;
        if(canmake(ranks, n, mid)){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}

int main(){
    int n = 10;
    vector<int> ranks = {1,2,3,4};
    cout << mintime(ranks, n) << endl;
    return 0;
}
