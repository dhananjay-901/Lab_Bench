//we want to select k elements such that the minimum absolute difference between any two selected elements is maximised. to find the best such minimum difference, we binary search on the answer space. for each candidate difference mid, we greedily try to pick k elements such that the absolute difference between every consecutive pick is at least mid. sorting the array first is essential because it ensures that once we pick a number, we only need to check increasing values for valid selections

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool ispossible(vector<int>& arr, int k, int mid){
    int count = 1;
    int last = arr[0];

    for(int i=0;i<arr.size();i++){
        if(arr[i] - last >= mid){
            count++;
            last = arr[i];
        }
        if(count == k){
            return true;
        }
    }
    return false;
}

int maxmindiff(vector<int>& arr, int k){
    sort(arr.begin(), arr.end());

    int low = 0;
    int high = arr.back() - arr.front();
    int answer = 0;

    while(low <= high){
        int mid = (low + high)/2;

        if(ispossible(arr,k,mid)){
            answer = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return answer;
}

int main(){
    vector<int> arr = {1,4,9,0,2,13,3};
    int k = 4;
    cout << maxmindiff(arr, k) << endl;
    return 0;
}
