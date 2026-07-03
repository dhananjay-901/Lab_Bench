/*The approach is mainly based on the following facts:

If we consider a subarray arr[left...right], we can decide the amount of water either for arr[left] or arr[right] if we know the left max (max element in arr[0...left-1]) and right max (max element in arr[right+1...n-1].
If left max is less than the right max, then we can decide for arr[left]. Else we can decide for arr[right]
If we decide for arr[left], then the amount of water would be left max - arr[left] and if we decide for arr[right], then the amount of water would be right max - arr[right].
How does this work?

Let us consider the case when left max is less than the right max. For arr[left], we know left max for it and we also know that the right max for it would not be less than left max because we already have a greater value in arr[right...n-1]. So for the current bar, we can find the amount of water by finding the difference between the current bar and the left max bar.*/

#include <iostream>
#include <vector>
using namespace std;

int maxWater(vector<int> &arr) { 
    int left = 1;
    int right = arr.size() - 2;
    int lMax = arr[left - 1];
    int rMax = arr[right + 1];

    int res = 0;
    while (left <= right) {
        if (rMax <= lMax) {
            res += max(0, rMax - arr[right]);
            rMax = max(rMax, arr[right]);
            right -= 1;
        } else { 
            res += max(0, lMax - arr[left]);
            lMax = max(lMax, arr[left]);
            left += 1;
        }
    }
    return res;
}

int main() {
    vector<int> arr = {2, 1, 5, 3, 1, 0, 4};
    cout << maxWater(arr) << endl;
    return 0;
}