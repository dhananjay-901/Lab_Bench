//using cycle detection
/*this approach uses cycle detection method to find out the minimum number of swaps required to sort the array. if an element is not in its correct position, it indicates that is a part of a cycle with one or more other elements that also need to be moved. for example, if element a is in the position of element b and element b is in the position of element c and so on. until it comes back to A, it forms a cycle. and to sort the elements in the cycle, we need cycle size-1 swaps, as each swap places one element in its correct position and the last element will automatically be in its correct place we use a hash map to store the original indices of each element and a visited array to mark elements that have already been included in cycle. next we sort the array. as we traverse it, if an element hasn't been visited and isn't in its correct position, we trace the cycle formed by the misplaced elements and find its size. the swap count is then updated by cyclesize-1*/

#include <bits/stdc++.h>
using namespace std;

int minSwaps(vector<int> &arr) {
  	int n = arr.size();
  	bool vis[n] = {0};
  	unordered_map<int, int> pos;
    for (int i = 0; i < n; i++)
        pos[arr[i]] = i;
    sort(arr.begin(), arr.end());
    int swaps = 0;
    for (int i = 0; i < n; i++) {
        if (vis[i] || pos[arr[i]] == i)
            continue;
        int j = i, cycleSize = 0;
        while (!vis[j]) {
            vis[j] = true;
            j = pos[arr[j]];
            cycleSize++;
        }
        if (cycleSize > 0) {
            swaps += (cycleSize - 1);
        }
    }
    return swaps;
}
int main() {
    vector<int> arr = { 10, 19, 6, 3, 5 };
    cout << minSwaps(arr);
    return 0;
}