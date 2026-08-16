//At low or high heights, the cost increases due to excessive changes in heights. As we move toward an optimal height, the cost decreases, reaches a minimum, then increases again — forming a V-shape (unimodal  pattern). This allows us to use Ternary search to efficiently find the minimum cost.

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int costOfOperation(vector<int>& heights, vector<int>& cost,int target) {
    int totalCost = 0;
    int n = heights.size();
    for (int i = 0; i < n; i++) {
        totalCost += abs(heights[i] - target) * cost[i];
    }
    return totalCost;
}

int minCost(vector<int>& heights, vector<int>& cost) {
    int low = *min_element(heights.begin(), heights.end());
    int high = *max_element(heights.begin(), heights.end());
    int minimumCost = INT_MAX;
    while (low <= high) {
        int mid1 = low + (high - low) / 3;
        int mid2 = high - (high - low) / 3;
        int cost1 = costOfOperation(heights, cost, mid1);
        int cost2 = costOfOperation(heights, cost, mid2);
        minimumCost = min({minimumCost, cost1, cost2});

        if (cost1 == cost2) {
            low = mid1 + 1;
            high = mid2 - 1;
        }
        else if (cost1 < cost2) {
            high = mid2 - 1;
        }
        else {
            low = mid1 + 1;
        }
    }
    return minimumCost;
}

int main() {
    vector<int> heights = {1, 2, 3};
    vector<int> cost = {10, 100, 1000};
    cout << minCost(heights, cost);
    return 0;
}
