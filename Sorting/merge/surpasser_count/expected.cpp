#include <bits/stdc++.h>
using namespace std;
/*in this approach we use the merge sort of merge sort. during the merge if the ith element in the left half is smaller than jth element in the right half, it means that all remaining elements in the right half [from j to end are greater than the ith element in the left half(since both halves are sorted). therefore we add the number of remaining elements in the right half to the surpasser count of the ith element of the left half, this process is repeated for all element in the left half as they merged with the right half.]*/

/*since all the element in the array are distinct we use a hash map to keep store of the surpasser count for each element. after the merge sort is complete, we fill the result array with surpasser counts, mainting the same order as the original input*/

void merge(vector<int>& arr, int low, int mid, int high, unordered_map<int, int>& m){
    int n1 = mid - low + 1;
    int n2 = high - mid;
    vector<int> left(n1), right (n2);

    for(int i = 0; i < n1; i++){
        left[i] = arr[low + i];
    }
    for(int j = 0; j < n2; j++){
        right[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = low;

    while( i < n1 && j <n2){
        if(left[i] < right[j]){
            m[left[i]] += n2 - j;
            arr[k++] = left[i++];
        }else{
            arr[k++] = right[j++];
        }
    }
    while(i < n1){
        arr[k++] = left[i++];
    }
    while(j < n2){
        arr[k++] = right[j++];
    }
}

void mergesort(vector<int>& arr, int low, int high, unordered_map<int, int>& m){
    if(low < high){
        int mid = low + (high - low)/2;
        mergesort(arr, low, mid, m);
        mergesort(arr, mid + 1, high, m);

        merge(arr, low, mid, high, m);
    }
}

vector<int> findsurpasser(vector<int>& arr){
    int n = arr.size();
    unordered_map<int, int> m;
    vector<int> dup = arr;
    mergesort(dup, 0, n-1, m);
    vector<int> res(n);
    for(int i = 0; i<n;i++){
        res[i] = m[arr[i]];
    }
    return res;
}

int main(){
    vector<int> arr = {2,7,5,3,8,1};
    vector<int> res = findsurpasser(arr);
    for(auto count:res){
        cout << count << "\n";
    }
    return 0;
}