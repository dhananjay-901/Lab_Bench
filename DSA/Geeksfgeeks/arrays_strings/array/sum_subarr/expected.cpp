#include <iostream>
#include <vector>
using namespace std;

int subarraysum(vector<int>& arr){
    int n = arr.size();
    int result = 0;

    for(int i=0;i<n;i++){
        result += (arr[i] * (i+1) * (n-i));
    }
    return result;
}

int main(){
    vector<int> arr = {1,4,5,3,2};
    int n = arr.size();
    cout << subarraysum(arr);
    return 0;
}
