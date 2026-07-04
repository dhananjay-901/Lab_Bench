/*the idea is to first check if 1 is present in the array or not. if not the answer is 1. otherwise replace all the numbers outside the range[1,n] to 1. then iterate over the array again and mark the occurences of each number say x by adding n to index x-1. lastly iterate over the array again to find the missing element by searching for the first unmarked index.*/

#include <iostream>
#include <vector>
using namespace std;

int missingnumber(vector<int>& arr){
    int n = arr.size();
    bool flag = false;
    for(int i=0;i<n;i++){
        if(arr[i] == 1){
            flag = true;
            break;
        }
    }

    if(flag == false) return 1;
    for(int i=0;i<n;i++){
        if(arr[i]<=0 || arr[i]>n) arr[i] = 1;
    }

    for(int i=0;i<n;i++){
        arr[(arr[i]-1)%n]+=n;
    }

    for(int i=0;i<n;i++){
        if(arr[i]<=n) return i+1;
    }

    return n+1;
}

int main(){
    vector<int> arr = {2,-3,4,1,1,7};
    cout << missingnumber(arr);
    return 0;
}