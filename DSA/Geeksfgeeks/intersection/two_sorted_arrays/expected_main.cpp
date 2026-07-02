/*The idea is based one merge function to merge two sorted arrays.

We simultaneously traverse both a[] and b[] from the left side. While traversing, we avoid duplicates in a[]. We do not need to do it for b[] because once we have a match, we move ahead in a[] and b[] both.
If current elements are not same, we skip the smaller of the two. If current element of a[] is smaller, we move ahead in a[] and if current of b[] is smaller, we move ahead in b[].
Else (If same), we add one occurrence of the current element to the result and move ahead in both a[] and b[].*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> intersection(vector<int>& a, vector<int>& b){
    vector<int> res;
    int m = a.size();
    int n = b.size();

    int i = 0, j = 0;
    while(i < m && j < n){
        if(i > 0 && a[i-1] == a[i]){
            i++;
            continue;
        }
        if(a[i]<b[j]){
            i++;
        }
        else if(a[i] > b[j]){
            j++;
        }
        else{
            res.push_back(a[i]);
            i++;
            j++;
        }
    }
    return res;
}
int main(void){
    vector<int> a = {1,1,2,2,2,4};
    vector<int> b = {2,2,4,4};

    vector<int> result = intersection(a, b);
    for(int num:result) cout << num << "\n";
    return 0;
}