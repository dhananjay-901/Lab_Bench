/*Given an integer array arr[], find the sum of any two elements whose sum is closest to zero.

Note: In case if we have two ways to form sum closest to zero, return the maximum sum among them.*/

/*the idea is to use the naive method that checks the sum of every possible pair of elements in the array an dkeeps track of the pair with the minimum absoute sum*/

#include <bits/stdc++.h>
using namespace std;

int closesttozero(vector<int>& arr){
    int res = arr[0] + arr[1];

    for(int i = 0; i < arr.size() - 1; i++){
        for(int j = i + 1; j < arr.size(); j++){
            int sum = arr[i] + arr[j];

            if(abs(sum) < abs(res)){
                res = sum;
            }
            else if(abs(sum) == abs(res)){
                res = max(res, sum);
            }
        }
    }
    return res;
}

int main(void){
    vector<int> arr = {0,-8,-6, 3};
    cout << closesttozero(arr) << "\n";
    return 0;
}