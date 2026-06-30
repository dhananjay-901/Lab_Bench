//naive approach
/*Given two sorted arrays a[] and b[], the task is to return union of both the arrays in sorted order. Union of two arrays is an array having all distinct elements that are present in either array. The input arrays may contain duplicates.*/

/*The intuition behind this approach is to gather unique elements from two arrays by checking each element against the current result array. The idea is to traverse both the arrays and for each element, check if the element is present in the result or not. If not, then add this element to the result.*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findunion(vector<int>& a, vector<int>& b){
    vector<int> res;
    for(int i = 0; i < a.size(); i++){
        int j;
        for(j=0;j < res.size(); j++){
            if(res[j]==a[i]){
                break;
            }
        }
        if(j==res.size()){
            res.push_back(a[i]);
        }
    }

    for(int i = 0; i < b.size(); i++){
        int j;
        for( j = 0; j < res.size();j++){
            if(res[j]== b[i]){
                break;
            }
        }
        if(j==res.size()){
            res.push_back(b[i]);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main(void){
    vector<int> a = {1,1,2,2,2,4};
    vector<int> b = {2,2,4,4};
    vector<int> res = findunion(a,b);
    for(int i = 0; i < res.size();i++){
        cout << res[i] << "\n";
    }
    return 0;
}

/*Time Complexity: O((n + m)2), where n is size of a[] and m is size of b[]

Copying all elements from a[] to res[] takes O(n2) time.
Now in the worst case, there will be no common elements in a[] and b[]. So, to check if the first element of b[] is present in res[], we need n comparisons. Similarly, for second element of b[], we need (n + 1) comparisons. So for m elements, total number of comparisons will be: n + (n + 1) + (n + 2) …. (n + m) = (n * m) + (m2 / 2)
So, overall time complexity = O(n2 + n * m + m2)*/