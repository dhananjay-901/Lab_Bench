//the idea is to simulate the merging process of two sorted arrays without actually creating a new one. by iterating through both arrays  together until reaching the middle index. the algorithm keeps track of the last two selected elements

#include <iostream>
#include <vector>

using namespace std;

double medianof2(vector<int>& a, vector<int>& b){
    int n = a.size(), m = b.size();
    int i = 0, j = 0;

    int m1 = -1, m2 = -1;

    for(int count = 0; count <= (m+n)/2; count++){
        m2 = m1;
        if(i!=n && j!=m){
            m1 = (a[i] > b[j]) ? b[j++] : a[i++];
        }
        else if (i < n){
            m1 = a[i++];
        }
        else{
            m1 = b[j++];
        }
    }

    if((m+n)%2 == 1){
        return m1;
    }
    else{
        return (m1+m2) / 2.0;
    }
}

int main(){
    vector<int> arr1 = {-5,3,6,12,15};
    vector<int> arr2 = {-12,-10,-6,-3,4,10};

    cout << medianof2(arr1, arr2) << endl;
    return 0;
}
