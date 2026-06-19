//expected approach to solve the first and last occurence of a element in a data structure 

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int findlast(vector<int>& arr, int x){
        int n = arr.size();
        int left = 0; 
        int right = n-1;
        int last = -1;

        while (left<=right){
            int mid = (left+right)/2;

            if(x==arr[mid]){
                last = mid;
                left = mid+1;
            }

            else if(x<arr[mid]){
                right = mid - 1;
            }

            else{
                left = mid + 1;
            }
        }
        return last;
    }

    int findfirst(vector<int>& arr, int x){
        int n = arr.size();
        int left = 0;
        int right = n-1;
        int first = -1;

        while(left<=right){
            int mid = (left+right)/2;
            if(x==arr[mid]){
                first = mid;
                right = mid-1;
            }
            else if(x<arr[mid]){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return first;
    }
};

int main(){
    Solution s;
    vector<int> arr = {1, 3, 5, 5, 5, 5, 7, 123, 125};
    int key = 5;
    int first = s.findfirst(arr, key);
    int last = s.findlast(arr, key);
    cout << "First: " << first << "\n";
    cout << "Last: " << last << "\n";
    return 0;
}