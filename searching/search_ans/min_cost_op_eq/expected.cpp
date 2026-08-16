//At minimum or maximum heights, the cost increases due to many changes in heights. As we move toward a balanced height, the cost drops, reaches a minimum, then rises again — forming a V-shape. We use binary search by checking mid - 1, mid, and mid + 1 to move toward the side with lower cost and find the minimum cost efficiently.

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int findcost(vector<int>& heights, vector<int>& cost, int h){
  int res = 0;
  int n = heights.size();
  for(int i=0;i<n;i++){
    res+= cost[i] * abs(heights[i] - h);
  }
  return res;
}

int mincost(vector<int>& heights, vector<int>& cost){
  int n = heights.size();
  int mini = INT_MAX, maxi = INT_MIN;

  for(auto val : heights){
    mini = min(mini, val);
    maxi = max(maxi, val);
  }

  int low = mini, high = maxi;
  int ans;

  while(low <= high){
    int mid = low + (high - low) / 2;

    int val1 = findcost(heights, cost, mid - 1);
    int val2 = findcost(heights, cost, mid);
    int val3 = findcost(heights, cost, mid + 1);

    if(val2 <= val1 && val2 <= val3){
      ans = val2;
      break;
    }
    else if(val1 >= val2 && val2 >= val3){
      low = mid + 1;
    }
    else if(val2 >= val1 && val3 >= val2){
      high = mid - 1;
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
