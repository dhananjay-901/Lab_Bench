//given an array arr[] consisting of n integers, find all the array elements which occurs more than floor(n/3) times

//the idea is to iterate over all elements and count the frequency of the element in the array. if the frequency of the element is greater than floor(n/3) add it to the result. to avoid adding duplicate elements into the result, we can check if the element is already present in the result. we can stop the iteration if we have already found two majority elements.

#include <iostream>
#include <vector>
using namespace std;

vector<int> findmajority(vector<int>& arr){
    int n = arr.size();
    vector<int> res;

    for(int i=0;i<n;i++){
        int cnt = 0;
        for(int j=i;j<n;j++){
            if(arr[j] == arr[i]) cnt+=1;
        }

        if(cnt > (n/3)){
            if(res.size() == 0 || arr[i] != res[0]){
                res.push_back(arr[i]);
            }
        }

        if(res.size() == 2){
            if(res[0] > res[1]) swap(res[0], res[1]);
            break;
        }
    }
    return res;
}

int main(){
    vector<int> arr = {2,2,3,1,3,2,1,1};
    vector<int> res = findmajority(arr);
    for(int ele : res) cout << ele << " ";
    return 0;
}
