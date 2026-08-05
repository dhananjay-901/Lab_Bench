//using moore's voting algorithm
/*The algorithm is based on the idea that if an element occurs more than n/2 times, then all the remaining elements together must occur less than n/2 times.

While traversing the array, we maintain a candidate and a vote count:

If the current element matches the candidate, we increment the vote count.
If it does not match, we decrement the vote count.
When the vote count becomes 0, it means the current candidate cannot be the majority element, so we select a new candidate.
By the end of the first traversal, the remaining candidate is the potential majority element (if there is a majority element, then this elements has to be the one). A second traversal is required to verify whether it actually appears more than n/2 times.*/

#include <iostream>
#include <vector>

using namespace std;

int majorityelement(vector<int>& arr){
    int n = arr.size();
    int candidate = -1;
    int count = 0;

    for(int num : arr) {
        if(count == 0){
            candidate = num;
            count = 1;
        }
        else if(num == candidate){
            count++;
        }
        else{
            count--;
        }
    }

    count = 0;
    for(int num : arr){
        if(num==candidate){
            count++;
        }
    }

    if(count > n/2){
        return candidate;
    }else{
        return -1;
    }
}

int main(){
    vector<int> arr = {1,1,2,1,3,5,1};
    cout << majorityelement(arr) << endl;
    return 0;
}
