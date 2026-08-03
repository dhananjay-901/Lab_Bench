#include <iostream>
#include <vector>
using namespace std;

//using recursive approach
//
void printsubarrays(vector<int>& arr, int start, int end){
    if(end == arr.size()) return ;

    else if(start>end) printsubarrays(arr, 0, end+1);
    else{
        for(int i=start;i<=end;i++){
            cout << arr[i] << " ";
        }
        cout << endl;
        printsubarrays(arr, start + 1, end);
    }
}

int main(){
    vector<int> arr = {1,2,3};
    printsubarrays(arr,0,0);
    return 0;
}
