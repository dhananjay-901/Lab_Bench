/*The idea is to use hash sets to efficiently find the unique elements that are common to both arrays. One set (as) stores elements from the first array, and the other (rs) ensures each common element is added only once to the result.

Step By Step Implementations:

Initialize an empty array for result
Create a hash set as (Set of a[] elements) and put all distinct items of a[] into it. For example, if array is [1, 2, 1, 3, 1], as is going to store [1, 2, 3]
Create an empty hash set for result rs (Set of result elements)
Create an empty array res[] to store result
Traverse through all items of b[]. If an item is in as and not in rs, then add it to res[] and rs
Return res[]*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> intersect(vector<int>& a, vector<int>& b) {
    unordered_set<int> as(a.begin(), a.end());  
    unordered_set<int> rs;                    
    vector<int> res;                            
    for (int i = 0; i < b.size(); i++) {
        if (as.find(b[i]) != as.end() && 
            rs.find(b[i]) == rs.end()) {
            rs.insert(b[i]); 
            res.push_back(b[i]); 
        }
    }
    return res;
}

int main() {
    vector<int> a = {1, 2, 3, 2, 1};
    vector<int> b = {3, 2, 2, 3, 3, 2};
    vector<int> res = intersect(a, b);
    for (int i = 0; i < res.size(); i++) 
        cout << res[i] << " ";

    return 0;
}