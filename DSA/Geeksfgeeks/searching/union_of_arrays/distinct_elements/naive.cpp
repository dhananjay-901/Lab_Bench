//union of two arrays with distinct elements
/*given two arrays a[] b[] with distinct elements the task is to return union of both the arrays in any order

note: union of two arrays is an array having all distinct elements that are present in either array*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> findunion(vector<int>& a, vector<int>& b){
    vector<int> res = a;
    for(int i = 0 ; i < b.size(); i++){
        int j;
        for(j = 0; j < a.size(); j++){
            if(a[j]==b[i]){
                break;
            }
        }

        if(j == a.size()){
            res.push_back(b[i]);
        }
    }
    return res;
}

int main(void){
    vector<int> a = {1,2,3};
    vector<int> b = {5,2,7};

    vector<int> res = findunion(a,b);
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << "\n";
    }
    return 0;
}