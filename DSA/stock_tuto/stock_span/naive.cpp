#include <bits/stdc++.h>
using namespace std;
//the stock span problem is a financial problem where we have a series of daily price quotes for a stock and we need to calculate the span of stock price for all days.
// given an array arr[] representing daily stock prices, the stock span for the ith day is the number of consecutive days upto day i, for which the price of the stock is less than or equal to the price on day i, return the span of stock prices for each day in the given sequence.

//the idea is the check for each day, how many consecutive previous days had stock prices, less than or equal to the current day's prices. this can be done by moving leftwards fromt he current index until a higher price is found or the beginning of the array is reached
//
#include <iostream>
#include <vector>
using namespace std;

vector<int> calculatespan(vector<int>& arr){
    int n = arr.size();
    vector<int> span(n,1);
    for(int i =1;i<n;i++){
        for(int j = i-1;(j>=0) && (arr[i]>= arr[j]); j--){
            span[i]++;
        }
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
