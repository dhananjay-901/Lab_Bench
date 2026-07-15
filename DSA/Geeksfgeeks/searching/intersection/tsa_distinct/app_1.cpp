/*Given two sorted arrays a[] and b[] with distinct elements of size n and m respectively, the task is to find intersection (or common elements) of the two arrays. We need to return the intersection in sorted order.

Note: Intersection of two arrays can be defined as a set containing distinct common elements between the two arrays.*/

/*approaches same as unsorted arrays with distint elements - best time and space complexity/
the idea is to use the same approaches as discussed in intersection of two arrays with distinct elements. the most optimal approach is among them is to use the hash set which has the time complexity of o[n+m] and auxiliary space complexity of o[min(n,m)]*/

//expected approach - using merge step of merge sort 
/*The idea is to find the intersection of two sorted arrays using merge step of merge sort. We maintain two pointers to traverse both arrays simultaneously. 
If the element in first array is smaller, move the pointer of first array forward because this element cannot be part of the intersection.
If the element in second array is smaller, move the pointer of second array forward. If both elements are equal, add one of them and move both the pointers forward. This continues until one of the pointers reaches the end of its array.*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> intersection(vector<int>& a, vector<int>& b){
    vector<int> res;
    int i = 0, j = 0;
    while(i < a.size() && j < b.size()){
        if(a[i] < b[j]){
            i++;
        }else if(a[i] > b[j]){
            j++;
        }else{
            res.push_back(a[i]);
            i++;
            j++;
        }
    }
    return res;
}

int main(void){
    vector<int> a = {1,2,4,5,6};
    vector<int> b = {2,4,7,9};
    vector<int> res = intersection(a, b);
    for(int i = 0; i < res.size(); i++) cout << res[i] << " ";
    return 0;
}