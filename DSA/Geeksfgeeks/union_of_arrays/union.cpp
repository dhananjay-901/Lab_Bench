//union of two arrays
/*given two arrays a[] and b[] return union of both the arays in any order. note union of two arrays is an array having all distinct element that are present in either array*/

//naiv approach
#include <iostream>
#include <vector>
using namespace std;

vector<int> findunion(vector<int>& a, vector<int>& b){
    vector<int> res;

    for(int i = 0; i < a.size(); i++){
        int j;
        for(j=0;i<res.size();j++){
            if(res[j]==a[i]){
                break;
            }
        }
        if(j == res.size()){
            res.push_back(a[i]);
        }
    }

    for(int i = 0; i < b.size(); i++){
        int j = 0;
        for(j = 0; j < res.size();j++){
            if(res[j]==b[i]){
                break;
            }
        }
        if(j==res.size()){
            res.push_back(b[i]);
        }
    }
    return res;
}

int main(void){
    vector<int> a = { 1,2,3,2,1};
    vector<int> b = {3,2,2,3,3,2};

    vector<int> res = findunion(a,b);

    for(int i = 0; i<res.size(); i++ ){
        cout << res[i]<<"\n";
    }
    return 0;
}

/*
time complexity O((n+m)^2)
- inserting all elements from first array will take O(n^2) time.
- in the worst case, there will be no common elements in a[], b[] so while inserting elements from second array the first element needs n comparisions the second elements needs n+1 comparisons and so on. so total comparisons will n +  n+1 + n+2 ... n+m = O(n*m+m^2) time.
*/