#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
vector<int> findUnion(vector<int>& a, vector<int>& b) {
  	unordered_set<int> st;  
    for (int i = 0; i < a.size(); i++) 
      	st.insert(a[i]);
    for (int i = 0; i < b.size(); i++) 
      	st.insert(b[i]);
    vector<int> res;                            
  	for(auto it: st) 
      	res.push_back(it);   
    return res;
}
int main() {
    vector<int> a = {1, 2, 3, 2, 1};
    vector<int> b = {3, 2, 2, 3, 3, 2};
    vector<int> res = findUnion(a, b);
    for (int i = 0; i < res.size(); i++) 
        cout << res[i] << " ";
    return 0;
}