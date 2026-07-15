/*Given two sorted arrays a[] and b[], where each array may contain duplicate elements , return the elements in the intersection of the two arrays. Intersection of two arrays is said to be elements that are common in both arrays. The intersection should not count duplicate elements and the result should contain items in sorted order.*/

//naive approach 
/*Traverse through a[] and avoid duplicates while traversing. Since the arrays are sorted, we can avoid duplicates by matching with the previous element.
For every element of a[], check if it is in b[], If Yes, then add it to the result and do not traverse further in b[] to avoid duplicates.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> intersection(vector<int>& a, vector<int>& b){
    vector<int> res;
    int m = a.size();
    int n = b.size();

    for(int i = 0; i < m; i++){
        if(i > 0 && a[i-1]==a[i]){
            continue;
        }

        for(int j = 0; j < n; j++){
            if(a[i]==b[j]){
                res.push_back(a[i]);
                break;
            }
        }
    }
    return res;
}

int main(void){
    vector<int> a = {1,1,2,2,2,4};
    vector<int> b = {2,2,4,4};

    vector<int> result = intersection(a, b);
    for(int num:result) cout << num << "\n";
    return 0;
}