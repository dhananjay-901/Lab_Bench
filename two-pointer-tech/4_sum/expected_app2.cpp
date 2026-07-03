/*we pick the first two elements using nested loops. for the remaining 2 elements we simply use hashing based 2 sum solution inside the two loops*/

#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;

bool check4sum(const vector<int>& arr, int target){
    int n = arr.size();
    unordered_map<int, pair<int,int>> mp;
    for(int i = 0; i < n-1;i++){
        for(int j = i+1; j<n; j++){
            mp[arr[i] + arr[j]] = {i,j};
        }
    }

    for(int i=0; i < n-1;i++){
        for(int j=i+1;j<n;j++){
            int sum = arr[i]+arr[j];
            if(mp.find(target - sum)!=mp.end()){
                pair<int, int> p = mp[target - sum];

                if(p.first != i && p.first != j && p.second != i && p.second != j){
                    return true;
                }
            }
        }
    }
    return false;
}

int main(){
    vector<int> arr = {1,1,1,1,1};
    int target = 4;
    cout << (check4sum(arr, target)?"true":"false");
    return 0;
}