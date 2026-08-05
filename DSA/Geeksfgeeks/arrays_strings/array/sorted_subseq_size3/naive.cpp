//given an array arr[] of n integers find the 3 elements such that a[i] > a[j] < a[k] and i<j<k in 0n time. if there are multiple such triplets then print any one of them.

/*The main motive is to find an element which has an element smaller than itself on the left side of the array and an element greater than itself on the right side of the array.

Create an auxiliary array smaller[0..n-1]. smaller[i] stores the index of a number which is smaller than arr[i] and is on the left side. The array contains -1 if there is no such element.
Create another auxiliary array greater[0..n-1]. greater[i] stores the index of a number which is greater than arr[i] and is on the right side of arr[i]. The array contains -1 if there is no such element.
Finally traverse both smaller[] and greater[] and find the index [i] for which both smaller[i] and greater[i] are not equal to -1.*/

#include <iostream>
#include <vector>
using namespace std;
vector<int> find3numbers(vector<int>& arr){
    int n = arr.size();

    vector<int> smaller(n,-1);
    int min = 0;
    for(int i=0;i<n;i++){
        if(arr[i] <= arr[min]) min = i;
        else smaller[i] = min;
    }

    vector<int> greater(n,-1);
    int max = n-1;
    for(int i=n-2;i>=0;i--){
        if(arr[i] >=arr[max]) max = i;
        else greater[i] = max;
    }

    for(int i=0;i<n;i++){
        if(smaller[i] !=-1 && greater[i]!=-1){
            return {arr[smaller[i]], arr[i], arr[greater[i]]};
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
