#include <iostream>
#include <vector>
using namespace std;

/*
we can use merge sort to count the inversions in an array, first we divide the array intwo halves left half and right half. next we recursively count the inversions in both hlaves. while merging the two halves back together, we also count how many elements from the left half array are greater than elements from the right half array, as these represent cross inversions [element from the left half of the array is greater than an element from the right half during the merging process in the merge sort algorithm]. finally we sum the inversions from the left half and right half and the corss inversions to get the total number of inversions in the array. this approach efficiently counts inversions which sorting the array.
*/

int countandmerge(vector<int>& arr, int l, int m, int r){
    int n1 = m-l+1, n2 = r-m;

    vector<int> left(n1), right(n2);
    for(int i = 0;i<n1;i++){
        left[i] = arr[i+l];
    }
    for(int j = 0;j<n2;j++){
        right[j] = arr[m+1+j];
    }

    int res = 0;
    int i = 0,j = 0,k = l;

    while(i < n1 && j < n2){
        if(left[i] <= right[j]){
            arr[k++] = left[i++];
        }else{
            arr[k++] = right[j++];
            res+=(n1-i);
        }
    }
    while(i<n2){
        arr[k++] = left[i++];
    }
    while(j<n2){
        arr[k++] = right[j++];
    }
    return res;
}

int countinv(vector<int>& arr, int l, int r){
    int res = 0;
    if(l<r){
        int m = (r+l)/2;

        res+= countinv(arr, l, m);
        res+= countinv(arr, m+1, r);

        res+=countandmerge(arr, l, m, r);
    }
    return res;
}

int inversioncount(vector<int>& arr){
    int n = arr.size();
    return countinv(arr, 0, n-1);
}

int main(void){
    vector<int> arr = {4,3,2,1};

    cout << inversioncount(arr) <<"\n";
    return 0;
}