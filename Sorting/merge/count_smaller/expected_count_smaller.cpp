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
    while ( i <= mid){
        t.push_back(v[i++]);
    }
    while(j<=h){
        t.push_back(v[j++]);
    }
    for(int k =0, idx = l; idx<=h;idx++,k++){
        v[idx] = t[k];
    }
}

void mergesort(vector<pair<int, int>>& v, vector<int>& ans, int i, int j){
    if(i<j){
        int mid = (i+j)/2;
        mergesort(v, ans, i, mid);
        mergesort(v, ans, mid + 1, j);
        merge(v, ans, i, mid, j);
    }    
}

vector<int> constructlowerarray(vector<int>& arr){
    int n = arr.size();
    vector<pair<int, int>> v;
    for(int i = 0;i < n; i++){
        v.push_back({arr[i], i});
    }
    vector<int> ans(n,0);

    mergesort(v, ans, 0, n-1);
    return ans;
}

void printarry(vector<int>& arr){
    int n = arr.size();
    for(int i = 0;i < n;i++){
        cout << arr[i] << "\n";
    }
}

int main(void){
    vector<int> arr = {12,1,2,3,0,11,4};
    vector<int> ans = constructlowerarray(arr);
    printarry(ans);
    return 0;
}