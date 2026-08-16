//given the heights of n towers in the array heights[] the task is to make all towers the same height by either adding or removing blocks. each addition or removal operation has a different cost for each tower, specified in the array cost[]. the objective is to minimise the total cost required to eqaulise the heights of all towers

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int mincost(vector<int>& heights, vector<int>& cost){
    int n = heights.size();
    int ans = INT_MAX;
    for(int i=0;i<n;i++){
        int total = 0;
        for(int j=0;j<n;j++){
            total+= cost[j] * abs(heights[j] - heights[i]);
        }
        if(total >= 0){
            ans = min(ans,total);
        }
    }
    return ans;
}

int main(){
    vector<int> heights = {1,2,3};
    vector<int> cost = {10,100,1000};
    cout << mincost(heights, cost);
    return 0;
}
