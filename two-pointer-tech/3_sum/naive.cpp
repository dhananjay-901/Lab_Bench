/*Given an array arr[] and an integer sum, check if there is a triplet in the array which sums up to the given target sum.*/

/*a simple method is to generate all possible triplets and compare the sum of every triplet with the given target. if the sum is equal to the target return ture. otherwise return false*/

#include <iostream>
#include <vector>
using namespace std;

bool hastripletsum(vector<int>& arr, int target){
    int n = arr.size();
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                if(arr[i] + arr[j] + arr[k] == target){
                    return true;
                }
            }
        }
    }
    return false;
}
int main(void){
    vector<int> arr = {1,4,45,6,10,8};
    int target = 13;
    if(hastripletsum(arr, target)){
        std::cout << "Triplet found\n";
    }else{
        std::cout << "No triplet found\n";
    }
    return 0;
}