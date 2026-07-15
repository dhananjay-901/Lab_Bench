/*expected approach for this problem - union of two sorted arrays*/
/*The idea is to find the union of two sorted arrays using merge step in merge sort. We maintain two pointers to traverse both arrays simultaneously. 

If the element in first array is smaller, add it to the result and move the pointer of first array forward.
If the element in second array is smaller, add it to the result and move the pointer of second array forward. 
If both elements are equal, add one of them and move both the pointers forward.
Also, while traversing both the arrays, we will compare the current element with its previous element and skip the current element if it is same as previous element. This will ensure that the union will contain only distinct elements.*/

#include <bits/stdc++.h>
using namespace std;

vector<int> findunion(vector<int>& a, vector<int>& b){
    vector<int> res;
    int n = a.size();
    int m = b.size();

    int i = 0, j = 0;
    while(i < n && j < m){
        if(i > 0 && a[i-1] == a[i]){
            i++;
            continue;
        }

        if(j > 0 && b[j-1] == b[j]){
            j++;
            continue;
        }

        if(a[i]<b[j]){
            res.push_back(a[i]);
            i++;
        }else if(a[i] > b[j]){
            res.push_back(b[j]);
            j++;
        }else{
            res.push_back(a[i]);
            i++;
            j++;
        }
    }

    while(i < n){
        if(i > 0 && a[i-1] == a[i]){
            i++;
            continue;
        }
        res.push_back(a[i]);
        i++;
    }
    while(j < m){
        if(j > 0 && b[j-1] == b[j]){
            j++;
            continue;
        }
        res.push_back(b[j]);
        j++;
    }
    return res;
}

int main(void){
    vector<int> a = {1,1,2,2,2,4};
    vector<int> b = {2,2,4,4};
    vector<int> res = findunion(a,b);
    for(int x : res){
        cout << x << "\n";
    }
    return 0;
}