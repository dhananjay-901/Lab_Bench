/*two pointer technique 
the idea of this technique is to begin with two corners of the given array. we use two index variables left and right to traverse from both corners*/

#include <iostream>
#include <vector>
using namespace std;
bool twosum(vector<int>& arr, int target){
    int left = 0, right = arr.size() - 1;
    while(left < right){
        int sum = arr[left] + arr[right];

        if(sum == target){
            return true;
        }else if(sum < target){
            left++;
        }else{
            right--;
        }
    }
    return false;
}

int main(void){
    vector<int> arr = {-3, -1, 0,1,2};
    int target = -2;
    if(twosum(arr, target)){
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }
    return 0;
}

