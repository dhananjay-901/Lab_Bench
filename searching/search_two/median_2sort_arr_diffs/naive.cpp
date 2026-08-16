//given two sorted arrays a[] and b[] find the median of these sorted arrays. assume that the two sorted arrays are merged and then median is selected from the combined array.
//the idea is to combines both sorted arrays into a new array and then sorts it. once sorted, it finds the median by checking the total length. if the size is odd. it returns the middle element. if even the average is of the two middle elements. this method is straightforwad but not optimal in terms of time and space complexity

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double medianof2(vector<int>& a, vector<int>& b){
    vector<int> c(a.begin(), a.end());
    c.insert(c.end(), b.begin(), b.end());

    sort(c.begin(), c.end());

    int len = c.size();

    if(len%2 == 0){
        return (c[len / 2] + c[len/2 - 1]) / 2.0;
    }else{
        return c[len/2];
    }
}

int main(){
    vector<int> a = {-5,3,6,12,15};
    vector<int> b = {-12,-10,-6,-3,4,10};
    cout << medianof2(a,b) << endl;
    return 0;
}
