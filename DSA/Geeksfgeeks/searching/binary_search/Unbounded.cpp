//unbounded binary search - find the point where a monotonically increasing function becomes positive first time
/*
Given a function 'int f(unsigned int x)' which takes a non-negative integer 'x' as input and returns an integer as output. The function is monotonically increasing with respect to the value of x, i.e., the value of f(x+1) is greater than f(x) for every input x. Find the value 'n' where f() becomes positive for the first time. Since f() is monotonically increasing, values of f(n+1), f(n+2),... must be positive and values of f(n-2), f(n-3), … must be negative. 
Find n in O(logn) time, you may assume that f(x) can be evaluated in O(1) time for any input x. 

A simple solution is to start from i equals to 0 and one by one calculate the value of f(i) for 1, 2, 3, 4 … etc until we find a positive f(i). This works but takes O(n) time.
Can we apply Binary Search to find n in O(Logn) time? We can't directly apply Binary Search as we don't have an upper limit or high index. The idea is to do repeated doubling until we find a positive value, i.e., check values of f() for following values until f(i) becomes positive.
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int f(int x) {return (x*x-10*x-20);}

class Solution{
    public:
    int findfirstpositive(){
        if(f(0)>0){
            return 0;
        }
        int i = 1;
        while(f(i)<=0){
            i = i*2;
        }
        return binary_search(i/2,i);
    }

    int binary_search(int low, int high){
        if(high >= low){
            int mid = low + (high - low)/2;

            if(f(mid)>0 && (mid == low || f(mid-1)<=0)){
                return mid;
            }
            if(f(mid)<=0){
                return binary_search((mid+1), high);
            }
            else{
                return binary_search(low, (mid-1));
            }
        }
        return -1;
    }
};

int main(void){
    Solution s;
    cout << s.findfirstpositive();
    return 0;
}