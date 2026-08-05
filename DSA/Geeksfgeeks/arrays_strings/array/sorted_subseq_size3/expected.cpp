/*First find two elements arr[i] & arr[j] such that arr[i] < arr[j]. Then find a third element arr[k] greater than arr[j]. We can think of the problem in three simple terms. First we only need to find two elements arr[i] < arr[j] and i < j. This can be done in linear time with just 1 loop over the range of the array. For instance, while keeping track of the min element, it is easy to find any subsequent element that is greater than it. Thus we have our arr[i] & arr[j]. Consider {3, 4, -1, 0, 2}. Initially min is 3, arr[i] is 3 and arr[j] is 4. While iterating over the array we can easily keep track of min and eventually update it to -1, so arr[i] & arr[j] become -1 and 0. As soon as we have arr[i] & arr[j] values, we can immediately start monitoring the subsequent elements in the same loop for an arr[k] > arr[j]. Thus we can find all three values arr[i] < arr[j] < arr[k] in a single pass over the array.*/
#include <iostream>
using namespace std;

vector<int> find3numbers(vector<int>& arr){
    int n = arr.size();
    if(n<3) return {};
    int first = INT_MAX;
    int second = INT_MAX;
    int prevfirst = INT_MAX;

    for(int i=0;i<n;i++){
        int x = arr[i];

        if(x<=first){
            first = x;
        }else if(x<=second){
            second = x;
            prevfirst = first;
        }else{
            return {prevfirst, second, x};
        }
    }
    return {};
}

int main(){
    vector<int> arr = {12,11,10,5,6,2,30};
    vector<int> res = find3numbers(arr);
    for(int x : res){
        cout << x << " ";
    }
    return 0;
}
