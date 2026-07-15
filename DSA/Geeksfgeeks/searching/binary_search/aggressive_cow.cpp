#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//given a array stalls[] representing the positions of stalls and an integer k denoting the number of aggressive cows, places the cows in stalls such that the minimum distnace between any two cows is as large as possible. return the maximum possible minimum distance.


// the naive approach = by iterating over all possible distances, the idea is to place k cows such that the minimum distance between an two is maximised. we sort the stalls and try all possible distances from 1 to the maximum gap between stalls. for each distance we check if cows can be placed by assigning the first last placed cow in at least that distance. if the placement is possible, we update our answer; the largest syck distance is returned.

//code for naive approach
class Solution{
    public:
    bool check(vector<int>& stalls, int k, int distance){
        int cnt = 1;
        int prev = stalls[0];
        for(int i=1;i<stalls.size(); i++){
            if(stalls[i]- prev >= distance){
                prev = stalls[i];
                cnt++;
            }
        }
        return (cnt >=k);
    }

    int aggressivecows(vector<int>& stalls, int k){
        sort(stalls.begin(), stalls.end());
        int res = 0;

        int mindist = 1;
        int maxdist = stalls.back() - stalls[0];

        for(int i=mindist; i<=maxdist; i++){
            if(check(stalls, k, i)){
                res = i;
            }
        }
        return res;
    }
};

int main(void){
    Solution s;
    vector<int> stalls = {1,2,3,4,8,9};
    int k = 3;
    int ans = s.aggressivecows(stalls,k);
    cout << ans <<"\n";
    return 0;
}