/*Given two arrays a[] and b[] with distinct elements of size n and m respectively, the task is to find intersection (or common elements) of the two arrays. We can return the answer in any order.

Note: Intersection of two arrays can be defined as a set containing distinct common elements between the two arrays.*/

/*the idea is to traverse the first array a[] and for each element from a[] check whether it is present in the array b[] if present then add this element to result array*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> intersection(vector<int>& a, vector<int>& b){
    vector<int> res;
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b.size(); j++){
            if(a[i]==b[j]){
                res.push_back(a[i]);
                break;
            }
        }
    }
    return res;
}

int main(void){
    vector<int> a = {1,2,3,4,5};
    vector<int> b = {2,3,4};

    vector<int> result = intersection(a, b);
    for(int num:result) cout << num << "\n";
    return 0;
}