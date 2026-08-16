//the approach is similar to the binary search approach of median of two sorted arrays of same size with only difference that we here apply binary search on the smallest array instead of a[]

#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

double medianof2(vector<int>& a, vector<int>& b){
    int n = a.size(), m = b.size();

    if(n>m){
        return medianof2(b,a);
    }

    int low = 0, high = n;

    while(low <= high){
        int mid1 = (low + high) / 2;
        int mid2 = (n+m+1)/2 - mid1;

        int l1 = (mid1 == 0 ? INT_MIN : a[mid1 - 1]);
        int r1 = (mid1 == n ? INT_MAX : a[mid1]);

        int l2 = (mid2 == 0 ? INT_MIN : b[mid2 - 1]);
        int r2 = (mid2 == m ? INT_MAX : b[mid2]);

        if(l1 <= r2 && l2 <= r1){
            if((n+m) % 2 == 0){
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
            else{
                return max(l1, l2);
            }
        }
        if(l1 < r2){
            high = mid1 - 1;
        }
        else low = mid1 + 1;
    }
    return 0;
}

int main(){
    vector<int> a = {-5,3,6,12,15};
    vector<int> b = {-12,-10,-6,-3,4,10};
    cout << medianof2(a,b);
    return 0;
}
