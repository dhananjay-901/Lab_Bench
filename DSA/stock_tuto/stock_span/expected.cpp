//The idea is to use a stack to directly find this first previous greater element for every day, instead of checking all consecutive smaller ones. Once we know that index, we can compute the span as: Span[i] = currentIndex − indexOfPreviousGreaterElement
//
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> calculatespan(vector<int>& arr){
    int n= arr.size();
    vector<int> span(n);
    stack<int> st;

    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()] <= arr[i]){
            st.pop();
        }

        if(st.empty()){
            span[i] = (i+1);
        }else{
            span[i] = (i-st.top());
        }
        st.push(i);
    }
    return span;
}

int main(){
    vector<int> arr = {10,4,5,90,120,80};
    vector<int> span = calculatespan(arr);
    for(int x : span){
        cout << x << " ";
    }
    return 0;
}
