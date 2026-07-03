/*the idea is to find the pair whose sum is closest to zero by sorting the array and using binary search for efficient lookup. for each element, we search for its closest complement using binary search, updating the closest sum found so far. if an exact zero sum is found, we return it immediately*/

/*Steps to implement the above idea:

Sort the array to enable binary search.
Iterate through each element and fix it as the first element of the pair.
Use binary search to find the closest second element.
Update the closest sum if the current pair gives a smaller absolute sum.
Return 0 if an exact zero sum pair is found.
Return the closest sum after checking all pairs.*/

#include <iostream>
#include <vector>
#include <algorithm>
#include<climits>
#include <cmath>
using namespace std;

int closesttozero(vector<int>& arr){
    sort(arr.begin(), arr.end());
    int n = arr.size();

    int res = INT_MAX;
    for(int i = 0; i < n; i++){
        int x = arr[i];
        int left = i + 1, right = n - 1;
        while(left <= right){
            int mid = (left + right) / 2;

            int curr = arr[mid] + x;

            if(curr == 0){
                return 0;
            }
            if(abs(curr) < abs(res)){
                res = curr;
            }
            else if(abs(curr) == abs(res)){
                res = max(res, curr);
            }

            if(curr < 0){
                left = mid + 1; 
            }else{
                right = mid - 1;
            }
        }
    }
    return res;
}

int main(void){
    vector<int> arr = {0,-8,-6,3};
    cout << closesttozero(arr) << "\n";
    return 0;
}