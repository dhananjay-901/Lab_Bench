//geek is organizing a party at his house. for the party he needs exactly n donuts for the guests. geeks decides to order the donuts from a nearby restuarant which has l checfs and each chef has a rank r. a chef with rank r can make 1 donut in first r minutes 1 more donut in next 2r minutes, 1 more donut in 3r minutes and so on. find the minimum time in which all the orders will be fulfilled

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

bool canmake(int n, vector<int>& rank, int timealloted){
    int cnt = 0;
    int l = rank.size();

    for(int i=0;i<l;i++){
        int timespent = 0;
        int r = rank[i];

        while(timespent + r <= timealloted){
            cnt++;
            timespent += r;
            r+=rank[i];
        }
    }
    return cnt >= n;
}

int mintime(int n, vector<int>& rank){
    int ans = -1;
    for(int i=1;i<=INT_MAX;i++){
        if(canmake(n,rank, i)){
            ans = i;
            break;
        }
    }
    return ans;
}

int main(){
    int n = 10;
    vector<int> rank = {1,2,3,4};
    cout << mintime(n, rank);
    return 0;
}
