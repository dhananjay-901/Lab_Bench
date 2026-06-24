#include <iostream>
#include <vector>
using namespace std;

int inversioncount(vector<int>& arr){
    int n = arr.size();
    int invcount = 0;

    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j<n;j++){
            if(arr[i]>arr[j]){
                invcount++;
            }
        }
    }

    return invcount;
}

int main(void){
    vector<int> arr = {4,3,2,1};
    cout << inversioncount(arr) << "\n";
    return 0;
}