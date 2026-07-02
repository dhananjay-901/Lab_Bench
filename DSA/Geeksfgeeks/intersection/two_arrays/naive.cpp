/*Given two arrays a[] and b[], find their intersection — the unique elements that appear in both. Ignore duplicates, and the result can be in any order.*/
//naive approach
/*the idea is to find all unique elements that appear in both arrays by checking each element of one array against the other and ensuring no duplicates are added to the result array 

Step By Step Implementation:

Initialize an empty array for result.
Traverse through a[] and for every element check if it is in b[], then check if it is already in result or not. If in b[] and not in result, then add it to the result.
Return result.*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> intersect(vector<int>& a, vector<int>& b){
    vector<int> res;

    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b.size(); j++){
            if(a[i] == b[j]){
                bool exists = false;
                for(int k = 0; k < res.size(); k++){
                    if(res[k] == a[i]){
                        exists = true;
                        break;
                    }
                }
                if(!exists){
                    res.push_back(a[i]);
                }
                break;
            }
        }
    }
    return res;
}

int main(void){
    vector<int> a = {1,2,3,2,1};
    vector<int> b = {3,2,2,3,3,2};

    vector<int> res = intersect(a, b);
    for(int i = 0; i<res.size(); i++){ cout << res[i] << "\n"; }
    return 0;
}