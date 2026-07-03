/*Hashing provides a more efficient solution to the 2-Sum problem. Rather than checking every possible pair, we store each number in an unordered set during iterating over the array's elements. For each number, we calculate its complement (i.e., target - current number) and check if this complement exists in the set. If it does, we have successfully found the pair that sums to the target. 

Step By Step Implementations:

Create an empty Hash Set or Unordered Set
Iterate through the array and for each number in the array:
=> Calculate the complement (target - current number).
=> Check if the complement exists in the set:
- If it is, then pair found.
- If it isn’t, add the current number to the set.
If the loop completes without finding a pair, return that no pair exists.*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool twoSum(vector<int> &arr, int target){
    unordered_set<int> s;
    for (int i = 0; i < arr.size(); i++){
        int complement = target - arr[i];
        if (s.find(complement) != s.end())
            return true;
        s.insert(arr[i]);
    }
    return false;
}
int main(){
    vector<int> arr = {0, -1, 2, -3, 1};
    int target = -2;
    if (twoSum(arr, target))
        cout << "true";
    else
        cout << "false";
    return 0;
}