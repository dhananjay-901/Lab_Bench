#include <bits/stdc++.h>
using namespace std;

/*timsort is a hybird alogrithm that uses the ideas of mergesort and insertion sort

used as default sorting algo in python sorted(), list.sort() and java for arrays.sort() on objects. the key idea behind the timsort is to identify small sorted segments of the array called runs and then merge them efficiently to form the fully sorted array.
*/

/*how timsort works?
identify runs: it scans the array to find small segments that are already sorted called runs. if a run is in desceding order, it is reversed to make it ascending

sort small runs: if a run is shorter than a fixed size, it is sorted using insertion sort, which is fast for small or nearly sorted data

merge runs: finally timsort merges these runs using that keep merging balanced and efficient similar to merge sort but optimized for real world data.
*/

const int minRUN = 32;
int calcminrun(int n){
    int r = 0;
    while(n>=minRUN){
        r|= (n&1);
        n>>=1; 
    }
    return n + r;
}

void insertionsort(vector<int>& arr, int left, int right){
    for(int i =left + 1; i <=right;i++){
        int key = arr[i];
        int j = i-1;
        while(j>=left && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
    arr[j+1] = key;
    }
}

void merge(vector<int>& arr, int l, int m, int r){
    vector<int> left(arr.begin() + l, arr.begin()+ m +1);
    vector<int> right(arr.begin() + m + 1, arr.begin() + r +1);

    int i =0 , j = 0 , k = l;
    while(i<left.size()&& j <right.size()){
        if(left[i] <= right[j]) arr[k++] = left[i++];
        else arr[k++] = right[j++];
    }
    while(i<left.size()) arr[k++] = left[i++];
    while(j<right.size()) arr[k++] = right[j++];
}

int findrun(vector<int>& arr, int start, int n){
    int end = start + 1;
    if(end == n) return end;
    if(arr[end] < arr[start]){
        while(end < n && arr[end] < arr[end - 1]) end++;
        reverse(arr.begin() + start, arr.begin() + end);
    }else{
        while(end < n && arr[end] >= arr[end -1]) end++;
    }
    return end;
}

void timsort(vector<int>& arr){
    int n = arr.size();
    int minRUN = calcminrun(n);
    vector<pair<int, int>> runs;

    int i = 0;
    while(i < n){
        int runend = findrun(arr, i, n);
        int runlen = runend - i;
        if(runlen < minRUN){
            int end = min(i + minRUN, n);
            insertionsort(arr, i, end - 1);
            runend = end;
        }
        runs.push_back({i, runend});
        i = runend;

        while(runs.size()>1){
            int l1 = runs[runs.size() - 2].first;
            int r1 = runs[runs.size() -2].second;
            int l2 = runs[runs.size() - 1].first;
            int r2 = runs[runs.size() - 1].second;

            int len1 = r1 - l1;
            int len2 = r2 - l2;
            if(len1 <= len2){

                merge(arr, l1, r1 - 1, r2 - 1);
                runs.pop_back();
                runs[runs.size() - 1] = {l1,r2};
            }else{
                break;
            }
        }
    }
    while(runs.size()>1){
        int l1 = runs[runs.size() - 2].first;
        int r1 = runs[runs.size() - 2].second;
        int l2 = runs[runs.size() - 1].first;
        int r2 = runs[runs.size() - 1].second;
        merge(arr, l1, r1 - 1, r2 - 1);
        runs.pop_back();
        runs[runs.size() - 1] = {l1, r2};
    }
}


int main(void){
    vector<int> arr = {5, 21, 7, 23, 19, 10, 1, 3, 2};
    timsort(arr);
    for(auto x :arr) cout << x << "\n";
    return 0;
}