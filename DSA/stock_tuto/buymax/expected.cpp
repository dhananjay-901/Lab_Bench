//expected approach
// the idea is to always buy the cheapest stocks first. since every purchased stock contributes equally to the answer, spedning the available budget on lower priced stocks maximuse the total number of stocks that can be bought. create a list of pairs(price, day) where day denotes the maximum number of stocks that can be purchased on that day. sort these pairs in ascending order of stock price. traverse the sorted list for each pair, buy as many stocks as possible without exceeding either the day's purchase limit or the remaining budget. update the answer and reduce the remaining amount accordingly
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int buymaxproducts(int k, vector<int> price){
    int n = price.size();
    vector<pair<int, int>> v;

    for(int i=0;i<n;++i){
        v.push_back(make_pair(price[i], i+ 1));
    }
    sort(v.begin(), v.end());

    int ans = 0;
    for(int i=0;i<n;i++){
        ans+=min(v[i].second, k/v[i].first);
        k-=v[i].first * min(v[i].second, (k/v[i].first));
    }
    return ans;
}

int main(){
    vector<int> price = {10,7,19};
    int k = 45;
    cout << buymaxproducts(k, price) << endl;
    return 0;
}
