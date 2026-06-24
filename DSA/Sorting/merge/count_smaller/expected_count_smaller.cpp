/*the idea is to use a modified merge sort. we sotre both element valyes and their original indices. while merging we count how mnay elements from the right half are smaller and add this count to the corresponding index's result*/

#include <bits/stdc++.h>
using namespace std;

void merge(vector<pair<int, int>>& v, vector<int>& ans, int l, int mid, int h){
    vector<pair<int, int>> t;
    int i = l;
    int j = mid + 1;

    while(i < mid +1 && j <= h ){
        if(v[i].first > v[j].first){
            ans[v[i].second] += (h-j+1);
            t.push_back(v[i]);
            i++;
        }else{
            t.push_back(v[j]);
            j++;
        }
    }
    
}