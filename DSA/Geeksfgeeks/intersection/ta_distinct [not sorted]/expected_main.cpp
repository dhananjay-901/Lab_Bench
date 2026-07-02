//better approach

/*The idea is to sort both the arrays and then maintain a pointer at the beginning of each array. By comparing the elements at both pointers, we can decide how to proceed:

If the element in the first array is smaller than the one in the second, move the pointer in the first array forward, because that element can't be part of the intersection. 
If the element in the first array is greater, move the second pointer forward. 
If the two elements are equal, you add that element to the result and move both pointers forward. 
This continues until one of the pointers reaches the end of its array. 

To know more about the implementation of this approach, please refer the post Intersection of Two Sorted Arrays with Distinct Elements. */

//expected approach
/*the idea is to use a hash set to store the elements of array a[]. then go through array b[] and check if each element is present in the hash set. if an element is found in the hash set add it the result array since it is a common element*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> intersection(vector<int>& a, vector<int>& b){
    unordered_set<int> st(a.begin(), a.end());
    vector<int> res;
    for(int i = 0; i < b.size(); i++){
        if(st.find(b[i]) != st.end()){
            res.push_back(b[i]);
        }
    }
    return res;
}

int main(void){
    vector<int> a = {5,6,2,1,4};
    vector<int> b = {7,9,4,2};
    vector<int> result = intersection(a, b);
    for(int num:result) cout << num << "\n";
    return 0;
}