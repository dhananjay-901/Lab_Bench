/*the idea is similar to cycle sort and move each element in the array to its correct position based on its value. so for each number say x sucht that 1 <=x<=n is placed at the (x-1)th index. finally iterate through the array and check if the numbers are in the expected indexes or not. the first place where the number doesn't match its index gives us the first missing positive number. if all the numbers from 1 to n are at their correct positions. then the next number n+1 is the smallest missing positive number*/

#include <iostream>
#include <vector>
using namespace std;

int missingnumber(vector<int>& arr){
    int n = arr.size();
    for(int i=0;i<n;i++){
        while(arr[i]>=1 && arr[i]<=n && arr[i]!=arr[arr[i]-1]){
            swap(arr[i], arr[arr[i]-1]);
        }
    }

    for(int i=1;i<=n;i++){
        if(i!=arr[i-1]){
            return i;
        }
    }
    return n+1;
}

int main(){
    vector<int> arr = {2,-3,4,1,1,7};
    cout << missingnumber(arr);
    return 0;
}