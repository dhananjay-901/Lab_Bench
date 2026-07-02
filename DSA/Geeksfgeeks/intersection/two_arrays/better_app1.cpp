/*The idea is to find common elements between two arrays without duplicates by:|
– Using a hash set to track already added elements,
– Checking each element of a[] against b[], and only adding it to the result if it's present in b[] and not already recorded.

Step By Step Implementation:

Initialize an empty hash set for storing result array elements
Traverse through a[] and for every element check if it is in b[], then check if it is already in result or not. If in b[] and not in the hash set, then add it to the hash set.
Create a result array and copy items of the hash set to the result array and return the result array.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> interset(vector<int>& a, vector<int>& b){
    vector<int> res;
    unordered_map<int, int> seen;
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b.size(); j++){
            if(a[i] == b[j] && !seen.count(a[i])){
                seen.insert({a[i], 1});
                res.push_back(a[i]);
            }
        }
    }
    return res;
}

int main(void){
    vector<int> a = {1,2,3,2,1};
    vector<int> b ={3,2,2,3,3,2};

    vector<int> res = interset(a, b);
    for(int i = 0; i<res.size(); i++){ cout << res[i] << " "; }
    return 0;
}