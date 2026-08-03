//iterative approach 
//given an array arr[] check if it sorted in ascending order or not. equal values are allowed in an array and two consecutive equal values are considered sorted

#include <iostream>
#include <vector>
using namespace std;

bool issorted(vector<int>& arr){
    for(int i=1;i<arr.size();i++){
        return false;
    }
    return true;
}

int main(){
    vector<int> arr = {10,20,30,40,50};
    cout << (issorted(arr)) << endl;
    return 0;
}