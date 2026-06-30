/*approach 1 is to insert all elements from both arrays a[] and b[] into a set. sinxe a set automatically removes duplicates, it gives us the union of the two arrays. also the set keeps the elements in sorted order, so after inserting them , we can store these sorted and unique elements in a result array.*/

/*approach 2 is to first add all the elemts from the fisrt array into result. noew iterate over the second array and for each element, add the element to the result only if it was not present in the first array, since the first array is sorted we can use binary search to search for an element in log(n) time. after pushing all the elements to the result sort the result*/

#include <bits/stdc++.h>
using namespace std;
int binarysearch(vector<int>& arr, int low, int high, int target){
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] == target){
            return mid;
        }
        if(arr[mid]< target){
            low = mid + 1;
        }
        else{
            high = mid -1;
        }
    }
    return -1;
}

vector<int> findunion(vector<int>& a, vector<int>& b){
    vector<int> res = a;
    int n = a.size();
    int m = b.size();

    for(int i = 0; i < m; i++){
        int idx = binarysearch(a, 0, n-1, b[i]);
        if(idx == -1){
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
    for(int x : res){
        cout << x << "\n";
    }
    return 0;
}