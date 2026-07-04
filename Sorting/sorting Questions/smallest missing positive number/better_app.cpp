/*the idea is to create a visited array, to keep track of which numbers from the original array were present. for each positive number in the input array. we mark its corressponding position in the visited array. after that we through the visited array to find the first position that isn't visited. the first unvisited index tells us the first missing positive number. note that we are marking numbers within the range from 1 to n only*/

#include <iostream>
#include <vector>
using namespace std;

int missingnumber(vector<int>& arr){
    int n = arr.size();
    vector<bool> vis(n, false);
    for(int i=0;i<n;i++){
        if(arr[i]>0 && arr[i]<=n) vis[arr[i]-1] = true;
    }

    for(int i=1;i<=n;i++){
        if(!vis[i-1]){
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