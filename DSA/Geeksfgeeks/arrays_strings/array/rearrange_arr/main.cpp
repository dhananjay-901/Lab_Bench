//given an array arr[] of size n, th task is to rearrange it in alternate positive and negative manner without changing the relative order of positive and negative numbers. in case of extra positive negative numbers they appear at the end of the array

#include <iostream>
#include <vector>
using namespace std;

void rearrange(vector<int>& arr){
    vector<int> pos, neg;

    for(int i=0;i<arr.size();i++){
        if(arr[i]>=0) pos.push_back(arr[i]);
        else neg.push_back(arr[i]);
    }

    int postidx = 0, negidx = 0;
    int i = 0;

    while(postidx<pos.size() && negidx<neg.size()){
        if(i%2==0) arr[i++] = pos[postidx++];
        else arr[i++] = neg[negidx++];
    }

    while(postidx < pos.size()) arr[i++] = pos[postidx++];
    while(negidx < neg.size()) arr[i++] = negidx;
}

int main(){
    vector<int> arr = {1,2,3,-4,-1,4};
    rearrange(arr);
    for(int i=0;i<arr.size();i++){
        cout << arr[i] << " ";
    }
    return 0;
}
