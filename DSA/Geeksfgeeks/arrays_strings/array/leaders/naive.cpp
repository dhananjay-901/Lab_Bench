//given an array arr[] of size n the task is to find all the leaders in the array. an element is a leader if it greater than a or equal to tall elements to its right side
//
#include <bits/stdc++.h>
using namespace std;
//naive approach - use two loops the outer loops from 0 to size-1 and one by one pick all elements from left tor ight. the inner loops compares the picked elements to all the elements on its right side. if the picked element is greater than all the elements to its right side, then the picked element is the leader

vector<int> leader(vector<int>& arr){
    vector<int> res;
    int n = arr.size();
    for(int i=0;i<n;i++){
        int j;
        for(int j=i+1;j<n;j++){
            if(arr[i] < arr[j]) break;
        }
        if(j==n) res.push_back(arr[i]);
    }
    return res;
}

int main(){
    vector<int> arr = {16,17,4,3,5,2};
    vector<int> result = leader(arr);
    for(int res : result){
        cout << res << " ";
    }
    cout << endl;
    return 0;
}
