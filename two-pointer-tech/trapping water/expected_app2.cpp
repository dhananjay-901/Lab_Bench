/*This approach involves using next greater and previous greaterelements to solve the trapping rainwater problem. By utilizing a stack and a single traversal, we can compute both the next and previous greater elements for every item. For each element, the water trapped can be determined by the minimum height between the previous and next greater elements. The water is filled between these elements, and the process continues recursively with the next greater and previous greater elements. */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int maxWater(vector<int>& arr) {
    stack<int> st;  
    int res = 0;
    for (int i = 0; i < arr.size(); i++) {
        while (!st.empty() && arr[st.top()] < arr[i]) {          
            
            int pop_height = arr[st.top()];
            st.pop();
          
            if (st.empty())
                break;
            int distance = i - st.top() - 1;
            int water = min(arr[st.top()], arr[i]) - pop_height;

            res += distance * water;
        }
        st.push(i);
    }
    return res;
}

int main() {
    vector<int> arr = {2, 1, 5, 3, 1, 0, 4};
    cout << maxWater(arr);
    return 0;
}