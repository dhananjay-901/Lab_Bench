/*given two sorted arrays a[] and b[] with distinct elements the task is to return union of both the arrays in sorted order*/

/*the idea is to add all the elements from the first array a[] to result array. then iterate through the second array b[] and add its elements to the result only if they were not present in a[], finally sort the result array to get the union in sorted order.*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> findunion(vector<int>& a, vector<int>& b){
    int n = a.size(), m = b.size();
    vector<int> res = a;

    for(int i = 0; i<m;i++){
        int j;
        for(j = 0;j < n; j++){
            if(a[j]==b[i]){
                break;
            }
        }

        if(j==n){
            res.push_back(b[i]);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main(void){
    vector<int> a = {1,2,3};
    vector<int> b = {2,5,7};

    vector<int> res = findunion(a,b);
    for(int i = 0; i<res.size();i++){
        cout << res[i] << "\n";
    }
    return 0;
}