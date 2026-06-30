/*expected approach using merge step of merge sort*/

/*the idea is to find the union of two sorted arrays using the merge step in merge sort. we maintain two pointers to traverse both arrays simultaneously

- if the element in first array is smaller, add it to the result and the move pointer of first array forward
- if the element in second array is smaller, add it to the result and move the pointer of second array forward
- if both elements are equall add one of the them and move both the pointers forward

once one array is fully traversed any remaining elements from the other array are added*/

#include <bits/stdc++.h>
using namespace std;

vector<int> findunion(vector<int>& a, vector<int>& b){
    vector<int> res;
    int n = a.size();
    int m = b.size();
    
    int i = 0, j = 0;
    while(i < n && j < m){
        if(a[i] < b[j]){
            res.push_back(a[i]);
            i++;
        }else if(a[i]>b[j]){
            res.push_back(b[j]);
            j++;
        }else{
            res.push_back(a[i]);
            i++;
            j++;
        }
    }

    while(i < n){
        res.push_back(a[i]);
        i++;
    }

    while(j < m){
        res.push_back(b[j]);
        j++;
    }
    return res;
}

int main(){
    vector<int> a = {1,2,3};
    vector<int> b = {2,5,7};

    vector<int> res = findunion(a,b);
    for(int x: res){
        cout << x << "\n";
    }
    return 0;
}