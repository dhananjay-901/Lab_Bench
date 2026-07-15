/*the idea is to use hash set, which helps in keeping only unique elements by removing duplicates. we first create an empty hash set and add elements from both arrays. the hash set ensures that no duplicates are stored. after adding all the elements we can create the final union array by iterating through the hash set*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> findunion(vector<int>& a, vector<int>& b){
    unordered_set<int> st;

    for(int i = 0; i < a.size(); i++){
        st.insert(a[i]);
    }

    for(int i = 0; i < b.size(); i++){
        st.insert(b[i]);
    }

    vector<int> res;

    for(auto it: st){
        res.push_back(it);
    }
    return res;
}

int main(void){
    vector<int> a = {1,2,3,2,1};
    vector<int> b = {3,2,2,3,3,2};

    vector<int> res = findunion(a,b);

    for(int i = 0; i < res.size(); i++){
        cout << res[i] << "\n";
    }
    return 0;
}